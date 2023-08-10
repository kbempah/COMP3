# Git Tutorials
I will be documenting some git help information here for easy reference as I learn how to use it.

## Basic Terminology:
commit -> a snapshot of directory. This is what is saved in git's history
staged file -> file ready to be included in next commit

- git help *command* -> Gets help on *command* from the manual pages.
- git init <dirname> -> initializes <dirname> as a git repo. If there are files already in <dirname>, they are initially untracked. Use git add <filename> to start tracking.
- git add <filename> -> stages <filename> and makes it ready for next commit
- git status -> shows detailed information about staged files.
- git diff -> shows items that have been modified but not staged/indexed. Essentially shows you the diff between . and staging area.
- git diff --staged -> shows items that will be included in the next commit.
- git rm *file* -> removes *file* from tracked directory. the git rm --cached option will stop tracking *file* but keep it in directory.
- git mv -> used to rename/move git-tracked files.

## Making Changes
- git log -> shows a detailed log of all previous commits.
- git log -n -> shows the last n previous commits.
- git log --oneline -> shows truncated SHA and commit message of previous commits.
- git checkout <branch> -> moves head ref to <branch>. This is a helpful command to explore previous commits.
- git checkout main/master -> moves head ref back to main.
- git tag -a <version_number> -m "<commit_message>" -> tags current head with alias <version_number>. current head can be referred to anytime by <version_number>. useful for marking important point in development. -a stands for **annotated tag**

## Working with remote repositories
- git remote -> this shows a listing of all remote repos
- git remote -v -> the -v option shows the URLs that git has stored for the repo used for reading and writing to the repo.