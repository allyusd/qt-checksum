mkdir _build
cd _build
cmake ../..

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    make
fi
