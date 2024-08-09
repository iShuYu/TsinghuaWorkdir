#!/usr/bin/env python
" tag project from lhcbdocs area."

def command_output(cmd):
  " Capture a command's standard output and errors. "
  import os
  (fin,fout,ferr) = os.popen3(cmd)
  fin.close()
  output = []
  while 1:
    line = fout.readline()
    if not line: break
    output += [ line.split('\n')[0] ]
  # print output
  errs = []
  while 1:
    line = ferr.readline()
    if not line: break
    errs += [ line.split('\n')[0] ]
  # print errs
  return (output, errs)
 
 
 
def main():
  usage = """usage: %prog <project_directory> [ <version_tag> [ <message_log_in_quotes> ] ]

                             <project_directory> - must be supplied (multiple / in the project_directory are allowed)
                             <version_tag> - any unique tag. If not given defaults to date in YYYY-MM-DD format
		  	     <message_log_in_quotes> - use if want to describe the tag meaning (mondane default supplied)	

	            enviromental variables used:
			DLHCB - lhcbdocs access string e.g. svn+ssh://underid@svn.cern.ch/reps/lhcbdocs
                                if not defined defualt will be used
                        USER  - userid to be used in lhcbdocs Users/ path (can be overwritten with the --u userid) 

          """    

  scriptn = "tagDoc"
  import os
  from optparse import OptionParser
  parser = OptionParser(usage=usage)
  parser.add_option("--list", "--list-vers",dest="list",
                    help="List available Project versions and its directory content and then exit.",
                    action="store_true", default=False)
  parser.add_option("--verb", "--verbose","--debug",dest="verbose",
                    help="Execute in verbose mode. Also activates --list without exit.",
                    action="store_true", default=False)
  parser.add_option("--u","--user",dest="user",
                    help="Overwrite default userid given by USER environemntal variable. Used in the repository path.",
                    default=os.getenv('USER'))
  parser.add_option("--test", "--t",dest="test",
                    help="Show resulting svn command without executing.",
                    action="store_true", default=False)
  parser.add_option("--type", "--doctype",dest="doctype",
                    help="Document type. Implemented types are= User | Note | Paper | PaperDraft | Template | ''.",
                    default="")
  (options, argum) = parser.parse_args()

  VERBOSE = options.verbose
  USERINP = options.user
  if USERINP:
	USERINP += "@"
  DLHCB = os.getenv('DLHCB')
  if DLHCB == None:
	# DLHCB = "https://svn.cern.ch/reps/lhcbdocs"
	DLHCB = "svn+ssh://" + USERINP + "svn.cern.ch/reps/lhcbdocs"
	print " $DLHCB not defined assuming =" + DLHCB 
  if VERBOSE:
	print scriptn+" verbose> options=",options 
	print scriptn+" verbose> arguments=",argum
	print scriptn+" verbose> DLHCB=",DLHCB
  errors = 0
  try:
	if len(argum) == 0:
		print scriptn+"> ERROR called without arguments. At least <project_directory> has to be supplied."
		return 1
	if len(argum) > 3:
		print scriptn+"> ERROR called with too many arguments=",argum
		parser.print_help()
		return 1

	allowed_types = [ "User","Note","Paper","PaperDraft","Template","" ]

	svnpath = DLHCB 	
	if options.doctype == "User":
		svnpath += "/Users/" + options.user
	elif options.doctype == "Note":
		svnpath += "/Notes" 
	elif options.doctype == "Paper":
		svnpath += "/Publications/CERN-EP-PH" 
	elif options.doctype == "PaperDraft":
		svnpath += "/Publications/PubDrafts"
	elif options.doctype == "Template":
		svnpath += "/Templates"
	elif options.doctype !="":		
		print scriptn + "> ERROR doctype=",options.doctype," not implemented"
		print scriptn + ">    allowed doctypes=",allowed_types
		return 1

	relpath = "/"+argum[0]

	cmd0 = "svn ls "+svnpath+relpath
	if VERBOSE: 
		print scriptn+" verbose> piping command=",cmd0
	(dircon,direrr) = command_output(cmd0)
	if len(direrr):
		print scriptn+"> ERROR listing "+svnpath+relpath
		print scriptn+">       Try again if you think communication with repository went down."  
                print scriptn+">       Otherwise try '/' as <project_directory> with --list option." 
		print scriptn+">       system errors:"
		for err in direrr:
			print err
		print scriptn+"> now print help"
		parser.print_help()
		return 1
	if VERBOSE:
		print scriptn+" verbose> output=",dircon
	tags = [] 
	tagdirname = ""
	for tagdir in ["drafts/","tags/"]:
		if tagdir in dircon:		
			cmd = cmd0 +"/"+tagdir
			if VERBOSE: 
				print scriptn+" verbose> piping command=",cmd
			(taggedout, taggederr) = command_output(cmd)
			if len(taggederr) > 0:
				print scriptn+"> ERRORS in tagdir? System error messages follow:"
				for err in taggederr:
		 			print err
				print scriptn+"> Try again before you give up. Perhaps repository went down."
				return 2
			for tag in taggedout:
				tags += [ tag.split('/')[0] ]
			tagdirname = tagdir
			break
	trunkdirname = ""
	for trunkdir in ["latest/","trunk/"]:
		if trunkdir in dircon:
			cmd = cmd0 +"/"+trunkdir
			(trunkout, trunkerr) = command_output(cmd)
			if len(trunkerr) > 0:
				print scriptn+"> ERRORS in trunkdir? System error messages follow:"
				for err in trunkerr:
		 			print err
				print scriptn+"> Try again before you give up. Perhaps repository went down."
				return 3
			trunkdirname = trunkdir
			break
	if options.list or VERBOSE:
		print " Project directory =",relpath," at ",svnpath
		print "     working subdirectory         =",trunkdirname
		print "     tagged versions subdirectory =",tagdirname," tags=",
		for tag in tags:
			print tag," ",
			if tag != tags[len(tags)-1]: print ", ",
		print
		print "     all files in this directory=",
		for ff in dircon:
			print ff," ",
			if ff != dircon[len(dircon)-1]: print ", ",
		print
		if options.list: return 0
	
	if trunkdirname == "":
		print scriptn + "> ERROR no 'latest' or 'trunk' subdirectories. Nothing to tag."
		return 1
		
	if tagdirname == "":
		print scriptn + "> ERROR no 'drafts' or 'tags' subdirectories. Create one first."
		return 2
		
	import datetime
        ver = datetime.datetime.now().date()
	if len(argum) > 1:
		ver = argum[1]
	if str(ver) in tags:
		print scriptn+"> ERROR the version_tag=",ver," already exist. Use a different one."
		print scriptn+">       list of existing version_tags=",tags
		return 3

	cmd = "svn cp "+svnpath+relpath+"/"+trunkdirname+" "+svnpath+relpath+"/"+tagdirname+str(ver)
	mess = " tagging "+relpath+" with tag="+str(ver)
	if len(argum) > 2:
		mess = argum[2]
	execu = cmd+" -m'"+mess+"'"
	if options.test:
		print scriptn+"> would execute ==>",execu
	else:
		if VERBOSE:
			print scriptn+" verbose> passing to os.system command="+execu
		os.system(execu)
  except:
      print scriptn+"> EXCEPTION CAUGHT: try again before you give up -------------> help printout follows "
      parser.print_help()
      errors += 1
  return errors
 
if __name__ == "__main__":
  import sys
  sys.exit(main())
