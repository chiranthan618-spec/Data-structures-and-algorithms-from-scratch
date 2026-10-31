# Git and Git Hub

Working directory and local depository are two complete different things. Working directory is nothing but the IDE folder we are coding on.

How to create git repository??

```
git init
```

This command initializes an empty repository. By default this command gives a master branch.

In order to delete the repository, go to the folder and turn on view hidden files, delete “.git” repository.

Converting the branch from master to main:

```
git init -b main
```

Now use “git status” to see the repository status.

Now configure the name and email for the repository:

```
git config --global user.name "Chiranthan"
git config --global user.email "chiranthan618@gmail.com"
```

Adding file to the staging area:

```
git add file_name
```

Adding all the files altogether in a folder:

```
git add .
```

Now moving the files from staging area to the repository:

```
git commit -m "commit_message"
```

use “git log” to view the commits and commit history

When you change something in a file which is already in the local commit, you can view the changes by using the command “git diff”. And to see the difference between the file in commit and file in staging area, use “git diff —staged”

Removing file from git repository:

If you just delete a file, it  will still remain in the git repository.

```
git rm --cached file_name
```

REMOTE REPOSITORY:

A repository for something in which multiple people or an organization to work on. The most famous is git Hub and git lab.

Now steps for adding my local repository into the remote repository:

```
mkdir chiru
cd chiru
echo "# chriru demo" >> README.md
ls -Force #to view our directory
```

This creates a directory and adds a file named README.md

Now steps to follow for git hub:

```
git init -b main
git add README.md
git commit -m "My first commit"
ssh-keygen -o #This is the creation of ssh key pair
#It willa sk for pass , empty

```

Now generating the ssh key which has to pasted in the github

```
cat C:\Users\chira\.ssh\id_ed25519.pub
cat .\id_ed25519.pub | clip #for copying it to clipboard

"ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIAwiCyiIq9c9mlv0dzVTTVdHlO8JIl6l1uXvoCciMPNr chira@Chiru_Desktop
The above code is pasted in the github
```

The above code is for setting up the SSH key in git hub which will be saved

Now the code to move a file from our local to remote depository:

```
git remote add origin git@github.com:chiranthan618-spec/My_Learning.git
#the git code will be copied from the git hub repository 
git push -u origin main
#This will push the file into the git hub.
```

If this is a **brand-new repository** that you just created, and you don't mind overwriting whatever is on GitHub right now (like a default `README.md` or `.gitignore` file that GitHub generated), you can force your local changes to overwrite the remote repository.

```
git push origin main --force
```

Adding tags for our different version of code:

Two types of tagging: 1)Annotated tagging 2)Lightweight tagging 

Example:

```
git tag -a v1.0 -m "1st tagging"
#here -a refers to annotated , v1.0 is the tag name
```

use “git tag” to see all the tags history.

This will not add the tag to the remote depository, we need to push the tag too.

```
git push origin v1.0
```

BRANCHES in Git:

Why do we need branch? - Let’s say our released version was not good enough. Then we use a different branch.

```
git checkout branch_name 
#to open the branch
#creating a new branch:
git checkout -b feature1
#for viewing all branches:
git branch
```

So when in feature1 branch, when we do any changes and commit, it will updated in feature1 not main.

Use “git switch main” to switch to back to the main branch. Similarly to the tag, branches won’t be pushed into the git hub remote. 

Creating branch using switch command:

```
git switch -c branch_name
#deleting a branch:
git branch -d branch_name
```

Pushing of Branch from local to git hub remote:

```
git push origin branch_name
```

NOTE: All the files in different branches will be removed or added accordingly.

Merging a branch with main:

```
git merge branch_name
#your current branch should be main for this.
```

all the features, files of feature1 will be merged with main.

Usually before merging:

```
git pull origin main
```