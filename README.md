# Homework 1

The problem statement can be found in the announce repo:

https://github.com/sc3260s17/announce/tree/master/hwk1 

## Cloning Repository and Pushing to Your Own Private Repo

Start by cloning this repo to your cluster home directory. Click the green "Clone or
download" button on this page in GitHub, then copy the URL provided and paste it after
typing `git clone`. If you get an HTTPS error, make sure you have the following line
in your ~/.bashrc file and then type `source ~/.bashrc`.

```
setpkgs -a git
```

Once you have the source files, you can begin making changes. You should
periodically commit your changes and push to GitHub. Your final solution must
be pushed to GitHub before class the date the assignment is due.
 
To stage, commit, and push to GitHub (must be inside repo):

    git status   # to check untracked files
	git add file1 file2 file3      # you can add as few as one file; avoid including large data files
	git commit -m "Initial copy of files into my private repo"     # make message meaningful
	git push

Then check GitHub to make sure everything looks okay. Remember to commit
and push often as you are editing the files to complete the assignment. You
may add additional files to the repo if you'd like.

