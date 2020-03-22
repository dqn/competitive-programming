# competitive-programming

## Run

```bash
$ g++ -Wall -std=c++14 <path>
$ ./a.out
# rm a.out
```

## Test

```bash
# Need `*.cpp` and `*.txt` in same directory
$ node test.js <path>
```

## Initialize for AtCoder

```bash
# Need `./template.cpp`
$ node init.js <url>
# => ./atcoder/abcXXX/x.cpp, ./atcoder/abcXXX/x.txt
```

### Bookmarklet for copy test cases

```js
javascript:(()=>{const e=document.createElement('textarea');e.value=Array.from(document.querySelector('.lang-ja').querySelectorAll('[id^=pre-sample]')).reduce((a,it,i)=>{(i%2)?a[a.length-1]+='\n'+it.textContent:a.push(it.textContent);return a;},[]).join('---\n');document.body.appendChild(e);e.select();e.focus();document.execCommand('copy');document.body.removeChild(e);alert('copied!');})();void 0;
```