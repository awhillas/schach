# Setup

## OS X

Bazel needs java8 (bug with java9 still)

    brew cask install caskroom/versions/java8
    brew install bazel

# Build instructions

## Bazel 

    bazel build //src:schach

## `make`

Ensure you have a recent version of the gnu compiler collection.

```
cd src
make
./schach
```

To clean:

```
cd src
make clean
```
