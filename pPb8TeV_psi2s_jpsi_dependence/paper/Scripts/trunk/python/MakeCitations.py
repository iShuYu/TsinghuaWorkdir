__author__ = 'P. Koppenburg'
import sys
import re
from ParseBib import *

class makeCitations :
    """
    run with 
    python MakeCitations.py [ <path-to-template>/LHCb-PAPER.bib ]

    will generate a file that can be included in any LHCb talk. It will
    produce a new command \LHCbCitation to be used as
    
    \LHCbCitation{LHCb-PAPER-2014-001}
    \LHCbCitation{LHCb-CONF-2014-001}

    The default is
    
    \LHCbCitation[\DefaultLHCbCitationStyle]{LHCb-PAPER-2014-001}

    where \DefaultLHCbCitationStyle is \tiny\blue.

    \setboolean{articletitles}

    will print the title in _before_ the citation

    @date 02-Jul-2018 Version 3.2 Bug fix. Slanted only applied to first letters. Now short format also allows title printing.
    @date 13-Nov-2017 Version 3.1 Bug fix. All short citations appeared double.
    @date 09-Nov-2017 Version 3.0 Split into two files
    @date 12-Aug-2015 Version 2.4 Also allows printing of titles for CONFs
    @date 19-May-2015 Version 2.3 \DefaultLHCbCitationStyle
    @date 28-Nov-2014 Version 2.2 Deal with joint papers
    @date 30-Aug-2014 Version 2.1 printing titles
    @date 07-Aug-2014 Version 2.0 making confs also
    @date 22-Jul-2014 Version 1.0 making papers
    
    """
    # Things you may want to change
    defaultBlue = "\\def\\CitationBlue{\\blue}" # This is the default colour (note the \\)
    defaultStyle = "\\tiny\\CitationBlue" # This is the default font (note the \\)
    default = "\DefaultLHCbCitationStyle" # This is the default font (note the \\)
    outfile = 'LHCbPapers.tex'
    titleFormat = "``\\textsl{"
    cdsString = "\\href{https://cds.cern.ch/search?ln=en&as=1&m1=p&f1=reportnumber&p1="

    
####################################################################
    def __init__(self, thefile = "LHCb-PAPER.bib", theConf = "LHCb-CONF.bib"):
        """
        Constructor
        """
        print "Using files", thefile, theConf
        self.file = thefile
        self.o = open(self.outfile, 'w')
        self.parseP = parseBib(thefile)
        self.parseC = parseBib(theConf,True)
   
####################################################################
    def do(self):
        """
        Do the parsining
        """
        self.o.write("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n")
        self.o.write("""%
% All LHCb papers in one command
% Use as
% \\newboolean{articletitles}
% \\setboolean{articletitles}{false}
% \\input{LHCbPapers}
% 
% \\LHCbCitation{LHCb-PAPER-2014-001}
% \\LHCbShortCitation{LHCb-PAPER-2014-001}
% 
% optionally (this is the default):
% 
% \\LHCbCitation[\\tiny\\blue]{LHCb-PAPER-2014-001}
% \\LHCbShortCitation{LHCb-PAPER-2014-001}
% 
% @author P. Koppenburg
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
""")
        self.o.write(self.defaultBlue+"\n")
        self.o.write("\\def"+self.default+"{"+self.defaultStyle+"}\n\n")
        #
        self.o.write("% \\notinmath ensures that if LHCbCitation is used in text mode it stays in text.\n")
        self.o.write("% If used in math mode it passes in text. This is not the same as \\text{} or \\mbox{}\n")
        self.o.write("% as they would create a non-breakable box.\n")
        #
        self.o.write("\\ifdefined\\notinmath\n")
        self.o.write("\\else\n")
        self.o.write("\\newcommand{\\notinmath}[1]{\\ifmmode\\text{#1}\\else#1\\fi}\n")
        self.o.write("\\fi\n\n")

        command = "\\LHCbCitation"
        shortcommand = "\\LHCbShortCitation"
        
#        self.o.write("\\newboolean{articletitles}\n")
#        self.o.write("\\setboolean{articletitles}{false}\n")
        self.o.write("\\newcommand{"+command+"}[2]["+self.default+"]{{\\notinmath{%\n")   
        self.parseP.parsePapers()
        self.parseC.parseConf()
        self.writePapers(self.parseP,False)
        self.writeConfs(self.parseC,False)
        self.o.write("}}}")
        self.o.write("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n")
        self.o.write("\\newcommand{"+shortcommand+"}[2]["+self.default+"]{{\\notinmath{%\n")           
        self.writePapers(self.parseP,True)
        self.writeConfs(self.parseC,True)
        self.o.write("}}}")
        

####################################################################
    def writePapers(self,parseP,short):
        """
        writes out papers
        """
        for b in parseP.bibitems:
            if (short): LHCb = ""
            else : LHCb = b.LHCb
            # print("PAPER", b.paper, "JOURNAL", b.journal, "VOL", b.volume, "PG", b.pages, "NOTE", b.note, "ARXIV", b.arxiv)
            theref = ""
            ## If there is already a journal -> published
            if (b.journal):
                if (short): 
                    theref = self.replace(b.journal+" "+b.volume)+" ("+b.year+") "+b.pages
                else: 
                    theref = self.replace(b.journal+" "+b.volume)+" ("+b.year+") "+b.pages+", arXiv:"+b.arxiv
                ## not yet published
            else :
                theref = "arXiv:"+b.arxiv 
            ## is there an arxiv?
            if (b.arxiv): 
                thestring = "\\href{http://arxiv.org/abs/"+b.arxiv+"}{"+theref+"}"
            ## Else under preparation
            else:
                thestring = self.cdsString+b.paper+"}{"+b.paper+"}"
            if (not short and b.note): thestring+=", "+b.note
            self.o.write("\\ifthenelse{\\equal{#2}{"+b.paper+"}}{"+self.printTitle(b,short)+"#1["+LHCb+thestring+"]}{}%\n")
            if (b.journal and not b.arxiv):
                print "Warning: Missing arxiv for PAPER", self.paper, "JOURNAL", self.journal, "VOL", self.volume, "PG", self.pages, "NOTE", self.note, "ARXIV", self.arxiv


####################################################################
    def writeConfs(self,parseC,short):
        """
        writes out CONFs
        """
        for b in parseC.bibitems:
#          print b.paper, b.note
          retired = ""
          if ("Retired" in b.note): retired = "{\\ \\bf (Retired)}"
          thestring = self.cdsString+b.paper+"}{"+b.paper+retired+"}"
          if (short): LHCb = ""
          else: LHCb = b.LHCb
          self.o.write("\\ifthenelse{\\equal{#2}{"+b.paper+"}}{"+self.printTitle(b,short)+"#1["+LHCb+thestring+"]}{}%\n")

        
####################################################################
    def printTitle(self,b,short=False):
        """
        Format title nicely
        """
#        if (short): return ""
        endFormat = ""
        if ("``" in self.titleFormat): endFormat = "''"
        if ("{" in self.titleFormat): endFormat = "}"+endFormat
        return "\\ifthenelse{\\boolean{articletitles}}{"+self.titleFormat+b.title+endFormat+" }{}"
       
####################################################################
    def replace(self,j): 
#        print "'", j, "'"
        j = j.replace("Phys. Rev. Lett.","PRL")
        j = j.replace("Phys. Rev. D","PRD ")
        j = j.replace("Phys. Lett. B","PLB ")
        j = j.replace("Eur. Phys. J. C","EPJC ")
        return j
##################################################################################

####################################################################
    def close(self): self.o.close()
##################################################################################
"""
Main
"""
if ( len(sys.argv) == 2 ):
    conf = sys.argv[1].replace("LHCb-PAPER.bib","LHCb-CONF.bib")
    m = makeCitations(sys.argv[1],conf)
else:
    m = makeCitations()
    
m.do()
m.close()
