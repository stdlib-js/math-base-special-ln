<!--

@license Apache-2.0

Copyright (c) 2018 The Stdlib Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

-->

# Natural Logarithm

[![NPM version][npm-image]][npm-url] [![Build Status][test-image]][test-url] [![Coverage Status][coverage-image]][coverage-url] <!-- [![dependencies][dependencies-image]][dependencies-url] -->

> Evaluate the [natural logarithm][natural-logarithm].

<section class="installation">

## Installation

```bash
npm install @stdlib/math-base-special-ln
```

Alternatively,

-   To load the package in a website via a `script` tag without installation and bundlers, use the [ES Module][es-module] available on the [`esm` branch][esm-url].
-   If you are using Deno, visit the [`deno` branch][deno-url].
-   For use in Observable, or in browser/node environments, use the [Universal Module Definition (UMD)][umd] build available on the [`umd` branch][umd-url].

</section>

<section class="usage">

## Usage

```javascript
var ln = require( '@stdlib/math-base-special-ln' );
```

#### ln( x )

Evaluates the [natural logarithm][natural-logarithm].

```javascript
var v = ln( 4.0 );
// returns ~1.386

v = ln( 0.0 );
// returns -Infinity

v = ln( Infinity );
// returns Infinity

v = ln( NaN );
// returns NaN
```

For negative numbers, the [natural logarithm][natural-logarithm] is **not** defined.

```javascript
var v = ln( -4.0 );
// returns NaN
```

</section>

<!-- /.usage -->

<section class="examples">

## Examples

<!-- eslint no-undef: "error" -->

```javascript
var randu = require( '@stdlib/random-base-randu' );
var round = require( '@stdlib/math-base-special-round' );
var ln = require( '@stdlib/math-base-special-ln' );

var x;
var i;

for ( i = 0; i < 100; i++ ) {
    x = round( randu() * 100.0 );
    console.log( 'ln(%d) = %d', x, ln( x ) );
}
```

</section>

<!-- /.examples -->

<!-- Section for related `stdlib` packages. Do not manually edit this section, as it is automatically populated. -->

<section class="related">

* * *

## See Also

-   <span class="package-name">[`@stdlib/math/base/special/exp`][@stdlib/math/base/special/exp]</span><span class="delimiter">: </span><span class="description">natural exponential function.</span>
-   <span class="package-name">[`@stdlib/math/base/special/log10`][@stdlib/math/base/special/log10]</span><span class="delimiter">: </span><span class="description">common logarithm (base ten).</span>
-   <span class="package-name">[`@stdlib/math/base/special/log1p`][@stdlib/math/base/special/log1p]</span><span class="delimiter">: </span><span class="description">evaluate the natural logarithm of 1+x.</span>
-   <span class="package-name">[`@stdlib/math/base/special/log2`][@stdlib/math/base/special/log2]</span><span class="delimiter">: </span><span class="description">binary logarithm (base 2).</span>

</section>

<!-- /.related -->

<!-- Section for all links. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->


<section class="main-repo" >

* * *

## Notice

This package is part of [stdlib][stdlib], a standard library for JavaScript and Node.js, with an emphasis on numerical and scientific computing. The library provides a collection of robust, high performance libraries for mathematics, statistics, streams, utilities, and more.

For more information on the project, filing bug reports and feature requests, and guidance on how to develop [stdlib][stdlib], see the main project [repository][stdlib].

#### Community

[![Chat][chat-image]][chat-url]

---

## License

See [LICENSE][stdlib-license].


## Copyright

Copyright &copy; 2016-2022. The Stdlib [Authors][stdlib-authors].

</section>

<!-- /.stdlib -->

<!-- Section for all links. Make sure to keep an empty line after the `section` element and another before the `/section` close. -->

<section class="links">

[npm-image]: http://img.shields.io/npm/v/@stdlib/math-base-special-ln.svg
[npm-url]: https://npmjs.org/package/@stdlib/math-base-special-ln

[test-image]: https://github.com/stdlib-js/math-base-special-ln/actions/workflows/test.yml/badge.svg?branch=main
[test-url]: https://github.com/stdlib-js/math-base-special-ln/actions/workflows/test.yml?query=branch:main

[coverage-image]: https://img.shields.io/codecov/c/github/stdlib-js/math-base-special-ln/main.svg
[coverage-url]: https://codecov.io/github/stdlib-js/math-base-special-ln?branch=main

<!--

[dependencies-image]: https://img.shields.io/david/stdlib-js/math-base-special-ln.svg
[dependencies-url]: https://david-dm.org/stdlib-js/math-base-special-ln/main

-->

[umd]: https://github.com/umdjs/umd
[es-module]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules

[deno-url]: https://github.com/stdlib-js/math-base-special-ln/tree/deno
[umd-url]: https://github.com/stdlib-js/math-base-special-ln/tree/umd
[esm-url]: https://github.com/stdlib-js/math-base-special-ln/tree/esm

[chat-image]: https://img.shields.io/gitter/room/stdlib-js/stdlib.svg
[chat-url]: https://gitter.im/stdlib-js/stdlib/

[stdlib]: https://github.com/stdlib-js/stdlib

[stdlib-authors]: https://github.com/stdlib-js/stdlib/graphs/contributors

[stdlib-license]: https://raw.githubusercontent.com/stdlib-js/math-base-special-ln/main/LICENSE

[natural-logarithm]: https://en.wikipedia.org/wiki/Natural_logarithm

<!-- <related-links> -->

[@stdlib/math/base/special/exp]: https://github.com/stdlib-js/math-base-special-exp

[@stdlib/math/base/special/log10]: https://github.com/stdlib-js/math-base-special-log10

[@stdlib/math/base/special/log1p]: https://github.com/stdlib-js/math-base-special-log1p

[@stdlib/math/base/special/log2]: https://github.com/stdlib-js/math-base-special-log2

<!-- </related-links> -->

</section>

<!-- /.links -->
