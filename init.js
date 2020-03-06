'use strict';

const fs = require('fs').promises;
const https = require('https');

function usage() {
  console.log('Usage: node testcase.js <url>');
  process.exit(0);
}

function get(url) {
  return new Promise((resolve, reject) => {
    let body = '';

    https.get(url, (res) => {
      res.on('data', (d) => {
        body += d.toString();
      });
      res.on('end', () => {
        resolve(body);
      });
    }).on('error', reject);
  });
}

function parse(html) {
  const matches = html.match(/<h3>.力例 \d<\/h3><pre>(.+?)<\/pre>/gs);
  const tests = [];
  const parseContent = (content) => {
    return content.match(/pre>(.+?)<\/pre/s)[1];
  };

  for (let i = 0; i < matches.length; i += 2) {
    const input = parseContent(matches[i]);
    const output = parseContent(matches[i + 1]);
    tests.push({ input, output });
  }

  return tests;
}

function makeTestContent(tests) {
  const contens = [];

  for (const test of tests) {
    contens.push(test.input + '\n' + test.output);
  }

  return contens.join('---\n').replace(/\r\n/g, '\n');
}

function makeDirName(url) {
  const splitted = url.split('/');
  const [ contest, probrem ] = splitted[splitted.length - 1].split('_');

  return { dir: `./atcoder/${contest}`, file: probrem };
}

async function createTestFile(path, tests) {
  const content = makeTestContent(tests);
  await fs.writeFile(path, content);
}

async function createSourceFile(path) {
  await fs.copyFile('./template.cpp', path);
}

async function main(argv) {
  const url = argv[2];

  if (!url) {
    usage();
  }

  const response = await get(url);
  const tests = parse(response);
  const { dir, file } = makeDirName(url);

  await fs.mkdir(dir, { recursive: true });
  await Promise.all([
    createTestFile(`${dir}/${file}.txt`, tests),
    createSourceFile(`${dir}/${file}.cpp`),
  ]);

  console.log('completed!')
}

if (require.main === module) {
  main(process.argv).catch(console.log);
}
