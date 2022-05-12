# ft_printf

### Prototype

int ft_printf(const char *, ...);

### Description

Write a library that contains ft_printf(), a function that will mimic the original printf()

### Conditions

1. 本家printf()のバッファ管理は実装しない。

Don’t implement the buffer management of the original printf().

1. この関数は次の変換を処理しなければなりません。(cspdiuxX%)

Your function has to handle the following conversions: cspdiuxX%

1. 作成した関数は、オリジナルのprintf()と比較されます。

Your function will be compared against the original printf().

1. ライブラリを作成するには、コマンド ar を使用する必要があります。libtoolコマンドの使用は禁止されています。

You must use the command ar to create your library. Using the libtool command is forbidden

1. libftprintf.aはリポジトリのルートに作成する必要があります。

Your libftprintf.a has to be created at the root of your repository.

### BONUS

1. 以下のフラグの任意の組み合わせを管理する。'-0.'と、すべての変換の下のフィールドの最小幅を管理する。

Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.

1. 以下のフラグをすべて管理する。'#  +' (はい、そのうちの1つはスペースです)

Manage all the following flags: ’# +’ (Yes, one of them is a space)

ボーナスパートを完成させるつもりなら、最初からボーナス機能の実装を考えてください。そうすれば、甘い考えによる落とし穴を避けることができます。

If you plan to complete the bonus part, think about the implementation of your extra features from the start. This way, you will avoid the pitfalls of a naive approach.

### S**pecification**

 `printf(”%[フラグ][最小フィールド幅].[精度][長さ修飾子][型]”)`

`printf(”%[flags][width][precision][modifier][type]”)`

**flags → 出力形式の決定**

**#**

xとX変換で先頭に0x（Xの場合0X）がつくように変換される。 実数変換では小数点に続く数字がないときでも小数点をつける。 gとG変換では、末尾の0が削除されない。

**+**

符号付き変換で、デフォルトでは負の場合にのみ-の符号がつくが、正の場合には+をつける。

**-**

フィールド幅指定の揃えを左揃えにする。

**0**

変換した値の左側を空白の代わりに0で埋める。

**（スペース）** 

符号付き変換で、デフォルトでは負の場合にのみ-の符号がつくが、正の場合に符号の位置に半角スペースを配置する。

**width →  変換した結果がその長さ以下であった場合に、左側が空白で埋められる**

**数字**

出力全体の桁数を指定する。　先頭に0をつけると余白を0で埋める。

**＊（ワイルドカード）**

引数で渡された値を width として使用する

**precision → 変換指定子によって意味が異なる**

**%d, u, i, x, X, p**

最低表示桁数を表し、足りない場合は0で埋められる

**%f**

小数点以下に表示する桁数を指定することになり、指定桁以上ある場合は切り捨てられる

**%s**

最大表示文字数を表し、この数値以上の文字列は切り捨てられる

**%c**

効果なし

**指定方法　→  10進数　or  ***

`.`（ピリオド）のみで数値を省略した場合、「精度」として、0を指定したのと同じ扱いとなる。

**modifier**

`hh`

整数変換に対して、引数がsigned char型かunsigned char型であること。
n変換に対して、引数が、signed char*型であることを示す。

`h`

整数変換に対して、引数がshort型かunsigned short型であること。
n変換に対して、引数が、short*型であることを示す。

`l`

整数変換に対して、引数がlong型かunsigned long型であること。
n変換に対して、引数が、long*型であること。*
c変換に対して、引数が、wint_t型であること。
s変換に対して、引数が、wchat_t型であることを示す。

`ll`

整数変換に対して、引数がlong long型かunsigned long long型であること。
n変換に対して、引数が、long long*型であることを示す。

`L`

実数変換に対して、引き数がlong doubleであることを示す。

`j`

整数変換に対して、引数がintmax_t型かuintmax_t型であることを示す。 intmax_t型は最大幅の符号付き整数、 uintmax_t型は最大幅の符号なし整数の型を示す定義型である。

`z`

整数変換に対して、引数がsize_t型、もしくはssize_t型であることを示す。 size_t型はサイズを表現するための整数型で、 ssize_t型はサイズ及びエラーを表現する整数型であり、 多くの場合、前者は符号なし整数、後者は符号付き整数の定義型である。

`t`

整数変換に対して、引数がptrdiff_t型であることを示す。 ptrdiff_t型はポインタ値の差を表現するための整数の定義型である。

**type → 型指定**

**%d,i**

intを引数として、10進数表記に変換する。%uは符号なし、d, iは符号付

**%o,u,x,X**

unsigned intを引数として、符号なしの、8進数(o)、10進数(u)、16進数(x, X)、へ変換する。 xとXの違いは、16進数表記で利用するアルファベットを小文字とするか、大文字とするかの違いである。

**%c**

int型を引数として、unsinged char型に変換し、対応する文字に変換する。

**%s**

const char *型、文字列へのポインタを引数として、指し示す文字列を出力する。 文字列はNULL文字'\0'で終端されている必要がある。

**%p**

引数をvoid *型とみなして、そのポインタの値（アドレス値）を16進数表記で出力する。 32bit環境であれば、ポインタ値をunsigned int値にキャストして%#xに渡した場合と同じになる。

**%%**

引数は取らず、一つの%に変換される。
