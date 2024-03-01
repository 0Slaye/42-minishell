#! /bin/sh
git add .
git commit -m "$@"
git push
echo "done."