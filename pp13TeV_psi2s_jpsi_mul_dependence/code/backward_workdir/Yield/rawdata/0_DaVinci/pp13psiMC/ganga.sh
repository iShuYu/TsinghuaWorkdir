#SHELL commands
lhcb-proxy-init
ganga
#ganga commands
:with open("a.py","r+") as f:
:exec(f.read())
:jobs
:jobs(93)

For downloading Tuple.root files from grid, use the following ganga command
:for js in jobs(93).subjobs.select(status='completed'): js.backend.getOutputData()

Tuple.root files can be found in
~/gangadir/workspace/xianglei/LocalXML/93/
