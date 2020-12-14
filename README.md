<a href="https://www.hardwario.com/"><img src="https://www.hardwario.com/ci/assets/hw-logo.svg" width="200" alt="HARDWARIO Logo" align="right"></a>

# HARDWARIO nanopb Protocol buffers encoder example

[![Travis](https://img.shields.io/travis/hardwario/lpwan-protob-endpoint-example/master.svg)](https://travis-ci.org/hardwario/lpwan-protob-endpoint-example)
[![License](https://img.shields.io/github/license/hardwario/lpwan-protob-endpoint-example.svg)](https://github.com/hardwario/lpwan-protob-endpoint-example/blob/master/LICENSE)
[![Twitter](https://img.shields.io/twitter/follow/hardwario_en.svg?style=social&label=Follow)](https://twitter.com/hardwario_en)

This is a simple example for encoding Google Protocol buffers using [nanopb](https://jpa.kapsi.fi/nanopb/) C library.

## Git clone

This project is using submodule for `nanopb` folder. Use `--recursive` command for clonning or use `git submodule init`.

## Dependencies

You have to install `protoc` Google Protocol buffers compiler. It is internally used by [nanopb](https://jpa.kapsi.fi/nanopb/docs/index.html).

## Usage

Edit your `message.proto` file. Set values of your fields in `main.c` and run `build.sh`. Script rebuilds the `.proto` file, builds project and executes `./a.out`.

Example output:
```
Length: 45
086410031A090801120548656C6C6F1A090801120548656C6C6F1A090801120548656C6C6F220608F60410CE09
```

## Simple nodejs decoder

In the `node_protob_decoder/` folder there is a simple decoder. You have to manually edit line containing hexadecimal message `b = Buffer.from('08641003', 'hex');` and then run the script by:

```
cd node_protob_decoder
npm install
node main.c
```

Example output
```
<Buffer 08 64 10 03 1a 09 08 01 12 05 48 65
6c 6c 6f 1a 09 08 01 12 05 48 65 6c 6c 6f 1a
09 08 01 12 05 48 65 6c 6c 6f 22 06 08 f6 04
10 ce 09>
{
    "luminance": 100,
    "hwRevision": "PB_REV1_2",
    "inputs": [
        {
            "state": true,
            "name": "Hello"
        },
        {
            "state": true,
            "name": "Hello"
        },
        {
            "state": true,
            "name": "Hello"
        }
    ],
    "voltage": {
        "battery": 630,
        "external": 1230
    }
}
```

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT/) - see the [LICENSE](LICENSE) file for details.

---

Made with &#x2764;&nbsp; by [**HARDWARIO s.r.o.**](https://www.hardwario.com/) in the heart of Europe.
