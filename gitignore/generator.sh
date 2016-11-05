rm -r -f gitignore/

git clone --depth 1 https://github.com/github/gitignore.git

cat Project.gitignore gitignore/VisualStudio.gitignore gitignore/C++.gitignore gitignore/Qt.gitignore gitignore/CMake.gitignore > ../.gitignore

rm -r -f gitignore/