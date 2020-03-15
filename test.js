'use strict';

const fs = require('fs').promises;
const cp = require('child_process');

const config = {
  bin: 'g++',
  options: [ '-Wall', '-std=c++14' ],
  testExtension: '.txt',
  after: 'rm ./a.out',
};

function usage() {
  console.log('Usage:');
  console.log('  node test.js <source path>');

  process.exit(0);
}

function colorize(str, color) {
  const palette = {
    red: '\u001b[31m',
    green: '\u001b[32m',
    reset: '\u001b[0m',
  };

  return palette[color] + str + palette.reset;
}

function print(str, color) {
  process.stdout.write(colorize(str, color));
}

function printFailure(failure) {
  console.log(`case ${failure.index + 1}: ${colorize('NG', 'red')}`);
  console.log('expect:');
  console.log(colorize(failure.expect, 'green'));
  console.log('actual:');
  console.log(colorize(failure.actual, 'red'));
  console.log();
}

function compile(bin, sourcePath, options = []) {
  const command = `${bin} ${options.join(' ')} ${sourcePath}`;
  const msg = cp.execSync(command).toString();

  if (msg) {
    console.log(msg);
  } else {
    console.log("compiled!");
  }
}

function parseTest(test) {
  const testDivider = '---';
  const inOutDivider = '\n\n';
  const tests = [];

  for (const testPair of test.split(testDivider)) {
    const [ input, output ] = testPair.split(inOutDivider).map((it) => it.trim());
    tests.push({ input, output });
  }

  return tests;
}

async function getTestsOf(sourcePath, testExtension) {
  const testPath = sourcePath.replace(/\.\w+/, testExtension);
  const test = (await fs.readFile(testPath)).toString();

  return parseTest(test);
}

function execTest(test, index) {
  const actual = cp.execSync('./a.out', { input: test.input }).toString().trim();

  if (actual === test.output) {
    print('.', 'green');
    return { index, status: 'success' };
  }

  print('F', 'red');
  return { index, status: 'failure', expect: test.output, actual };
}

function execTestsAsync(tests) {
  const promises = tests.map((test, i) => new Promise((r) => r(execTest(test, i))));

  return Promise.all(promises).then((items) => {
    console.log('\n');
    return items.filter((it) => it.status === 'failure');
  });
}

async function main(argv) {
  const sourcePath = argv[2];

  if (!sourcePath) {
    usage();
  }

  compile(config.bin, sourcePath, config.options);

  const tests = await getTestsOf(sourcePath, config.testExtension);
  const failures = await execTestsAsync(tests);

  config.after && cp.exec(config.after);

  for (const failure of failures) {
    printFailure(failure);
  }
}

if (require.main === module) {
  main(process.argv).catch(console.log);
}
