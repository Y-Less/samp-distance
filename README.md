# samp-distance

[![sampctl](https://shields.southcla.ws/badge/sampctl-samp--distance-2f2f2f.svg?style=for-the-badge)](https://github.com/kristoisberg/samp-distance)


## Installation

Simply install to your project:

```bash
sampctl package install kristoisberg/samp-distance
```

Include in your code and begin using the library:

```pawn
#include <samp-distance>
```

## Usage

<!--
Write your code documentation or examples here. If your library is documented in
the source code, direct users there. If not, list your API and describe it well
in this section. If your library is passive and has no API, simply omit this
section.
-->

## Testing

The library is not fully tested as of now because there is no fully working version of `ut_mock_player`/`y_mock` right now (I will be working on one soon). Right now, the tests only check whether the library compiles and the functions in the `Point-Point` section return the correct values. To test, simply run the package:

```bash
sampctl package run
```
