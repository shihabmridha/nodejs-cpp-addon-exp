// const addon = require('bindings')('app');
import bind from 'bindings';

export const addon = bind('app');

addon.test('key', (value: string) => {
  console.log(value);
});
