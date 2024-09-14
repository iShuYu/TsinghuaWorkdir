__author__ = 'P. Koppenburg'
import sys
import re
from ParseBib import *
import cPickle

class checkTitles :
    """
    run with 
    python CheckTitles.py <path-to-template>/LHCb-PAPER.bib 

    This will check that the titles in LHCb-PAPER.bib match those of arXiv.
    """
    
    bib = ""

####################################################################
    def __init__(self, thebib, pickle = '/afs/cern.ch/lhcb/project/web/Publications/working_dir/managers/dics.cpickle'):
        """
        Constructor
        """
        print "Using file", thebib
        self.parseP = parseBib(thebib)
        self.parseP.parsePapers()
        self.info = cPickle.load(open(pickle, 'r')) 
   
        self.readBib()

####################################################################
    def compareTitles(self,t1,t2):
        """
        Compare titles
        """
        oklist = [ '$' ]
        if (t1==t2): return True
        else:
            isok = True
            print "Different titles"
            print t1
            print t2
            for i,s in enumerate(difflib.ndiff(t1, t2)):
                if s[0]==' ': continue
                elif (s[-1] not in oklist):
                    if s[0]=='-': print(u'Delete "{}" from position {}'.format(s[-1],i))
                    if s[0]=='+': print(u'   Add "{}" to position {}'.format(s[-1],i))
                    isok = False
            if (isok): print "But differences are minor"
            return isok
        
####################################################################
    def readBib(self):
        """
        Read bibliography file and extract dictionary
        """
        print self.info.keys()
        print len(self.parseP.bibitems)
        for b in self.parseP.bibitems:
            thekey = b.paper.replace('LHCb-','')
            if thekey not in self.info.keys():
                print thekey, "not in pickle because `", b.note, "'"
                continue
            k = self.info[thekey]
            bibTitle = makeTitle(b.title) 
            dbTitle  = makeTitle(k['cds']['Title'])
            print "#####", b.paper                                           
            # print "Bib file:", b.arxiv, bibTitle
            # print "arXiv:   ", k['cds']['arXiv'], dbTitle
            if ( b.arxiv and b.arxiv != k['cds']['arXiv'] ):
                print "Inconsistent arXiv refs for",thekey, b.arxiv, k['cds']['arXiv']
                return
            self.compareTitles( bibTitle, dbTitle)
#                return

####################################################################
####################################################################
"""
Main
"""
if ( len(sys.argv) == 2 ):
    bib = sys.argv[1]
    c = checkTitles(bib)
elif ( len(sys.argv) == 3 ):
    bib = sys.argv[1]
    p = sys.argv[2]
    c = checkTitles(bib,p)

else: 
    print "Usage: python CheckTitles.py <path-to-template>/LHCb-PAPER.bib"
    exit 



    
