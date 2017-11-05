from __future__ import print_function

class datafile_by_index:
	def __init__(self, fn, indexlist):
		self._f = open(fn, "r")
		self._i = indexlist
		self._s = self._f.next()

		keys = []
		if(self._s[0]=='#'):
			keys = self._s[:-1].split()
		
		for i,k in enumerate(self._i):
			if type(k)==str:
				for j,l in enumerate(keys):
					if l==k:
						self._i[i]=j
						break;


	def __iter__(self):
		return self

	def next(self):
		return self.__next__()

	def __next__(self):
		self._s = self._f.next()
		while(self._s[0]=='#'):
			self._s = self._f.next()
		v = self._s.split()
		x = []

		for i in self._i:
			s = v[i]
			try:
				s = float(s)
			except ValueError:
				# it's not a string...
				pass
			x.append(s)

		return x
