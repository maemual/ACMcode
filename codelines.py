#!/usr/bin/env python
import os
import sys

EXT = ['.c','.cpp','.java','.py']

def main():
	l = []
	if os.path.isdir(sys.argv[1]):
		for root, dirs, files in os.walk(sys.argv[1]):
			l.extend([os.path.join(root, name) for name in files])
	else:
		l.append(sys.argv[1])

	params = ["'"+p+"'" for p in l if os.path.splitext(p)[1] in EXT]

	result = os.popen("wc -l %s "%" ".join(params)).read()
	print result

if __name__ == '__main__':
	main()
