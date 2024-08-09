__author__ = 'P. Koppenburg'
import sys
import re
import difflib

####################################################################
def makeTitle(title):
    title = title.replace("\t"," ").replace("\n"," ")
    if title[0] == "{": title = title[1:]
    if title[-1] == "}" : title = title[:-1]
    while ("  " in title):
        title = title.replace("  "," ")
    return title
        
####################################################################
class bibitem :
    """
    Contains bibliography items
    """
    LHCb = ""
    paper = ""
    arxiv = ""
    journal = ""    
    volume = ""
    pages = ""
    note = ""
    number = ""
    title = ""
    
####################################################################
    def getTitle(self,line,intitle):
        """
        Fill title
        """
        self.title = self.title.replace("\n"," ")+line.split('"')[0]
        if line.find('",')>0: intitle = False
        return intitle
        
####################################################################

class parseBib :
    """
    Helper class to parse bibliography files
    """

    # If you'd like to change any of that, let Patrick know.
    re_article = re.compile('@article{(.*)')
    re_conf = re.compile('@(lhcbreport|misc){(.*)')
    re_journal = re.compile('(.*)journal(.*)')
    re_volume = re.compile('(.*)volume(.*)')
    re_pages = re.compile('(.*)pages(.)')
    re_note = re.compile('(.*)note(.*)')
    re_arxiv = re.compile('(.*)eprint(.*)')
    re_end = re.compile('}')
    re_year = re.compile('(.*)year(.*)')    
    re_title = re.compile('(.*)title(.*)')
    re_collaboration = re.compile('(.*)collaboration(.*)')
    entrydone = False
    lines = []
    bibitems = []
   
####################################################################
    def __init__(self, thefile, conf = False):
        """
        Initialise from file
        """
        self.file = open(thefile)
        self.lines = self.file.readlines()
#        print len(self.lines)
        self.bibitems = []
        

####################################################################
    def parsePapers(self):
        """
        Do the parsing of lines of LHCb-PAPER.bib
        """
        intitle = False
        b =  bibitem()
        inBib = False
        for line in self.lines:
            if "%"==line[0] : continue
#            print line #, "In title", intitle
            if (intitle):
                intitle = b.getTitle(line,intitle)
#                print('Continue 1')
                continue
            intitle = False
            if (self.re_article.match(line)):
                inBib = True
                b.paper = line.split('{')[1].replace(",","").replace("\n","")
            if not inBib : continue # continue until we have a bibItem
            if (self.re_journal.match(line)):
                b.journal = line.split('"')[1]
            if (self.re_volume.match(line)):
                b.volume = line.split('"')[1]
            if (self.re_pages.match(line)):
                if '"' in line:
                    b.pages = line.split('"')[1]
                else:
                    b.pages = line.split('{')[1].split('}')[0]
            if (self.re_note.match(line)):
                b.note = line.split('"')[1].replace("{","").replace("}","")
            if (self.re_arxiv.match(line)):
                b.arxiv = line.split('"')[1]
            if (self.re_year.match(line)):
                b.year = line.split('"')[1]
            if (self.re_collaboration.match(line)):
                b.LHCb = (line.split('"')[1]).replace(" collaborations",", ").replace(" collaboration",", ")
            if (self.re_title.match(line)):
                b.title = line.split('"')[1]
                if (-1==line.find('",')): 
                    intitle = True
#                    print('Continue 2')
                    continue
                
#            print('matching end {0}'.format(self.re_end.match(line.lstrip())))
            if (self.re_end.match(line.lstrip())):
                #        print line
                b.title = makeTitle(b.title) 
#                print len(self.bibitems), b.paper
                self.bibitems.append(b)
                b = bibitem() # a new one
                inBib = False
   
####################################################################
    def parseConf(self):
        """
        Do the parsing of lines of LHCb-CONF.bib
        """
        intitle = False
        inBib = False
        b = bibitem()
        for line in self.lines:
            if "%"==line[0] : continue
            if (intitle):
                intitle = b.getTitle(line,intitle)
                continue
            intitle = False
            if (self.re_conf.match(line)):
                inBib = True
                b.paper = line.split('{')[1].replace(",","").replace("\n","")
            if not inBib : continue # continue until we have a bibItem
            if (self.re_collaboration.match(line)):
                b.LHCb = (line.split('"')[1]).replace(" collaborations",", ").replace(" collaboration",", ")
            if (self.re_note.match(line)):
                b.note = line.split('"')[1].replace("{","").replace("}","")
            if (self.re_title.match(line)):
                b.title = line.split('"')[1]
                if (-1==line.find('",')): 
                    intitle = True 
                    continue
            if (self.re_end.match(line)):
                self.bibitems.append(b)
                b = bibitem() # a new one
                inBib = False
