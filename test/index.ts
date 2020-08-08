import { addon } from '../lib/index';
import * as assert from 'assert';

addon.test('key', (value: string) => {
  assert.deepEqual(value, 'a string');
});
