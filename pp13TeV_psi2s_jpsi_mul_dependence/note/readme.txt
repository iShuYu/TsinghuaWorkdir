每次更新完之后：
git add * (如果涉及删除操作，git add --all *)
git commit -m "comment" (每次add都要commit)
git push overleaf master(上传到仓库)
如果告诉你Updates were rejected because the remote contains work that you do:
git add *
git pull overleaf master
git push overleaf master(先下载再上传)



(git config credential.helper store是用来储存的)
