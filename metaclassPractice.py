from inspect import Signature, Parameter
def make_signature(names):
	return Signature(Parameter(name, Parameter.POSITIONAL_OR_KEYWORD) for name in names)

class Descriptor:
	def __init__(self, name = None):
		self.name = name
	def __get__(self, instance, owner):
		print("Obtaining variable", self.name)
		return instance.__dict__[self.name]
	def __set__(self, instance, value):
		print("Setting variable", self.name)
		instance.__dict__[self.name] = value
	def __delete__(self, instance):
		print("Deleting variable", self.name)
		del instance.__dict__[self.name]

#METACLASSES BUILD THE OBJECT MAKER(CLASS)
class StructMeta(type):
	def __new__(cls, name, bases, dct):
		print("Call StructMeta.__new__() with class:", name, dct)
		clsObj = super().__new__(cls, name, bases, dct)
		sig = make_signature(clsObj._fields)
		setattr(clsObj, '__signature__', sig)
		return clsObj

#INHERITED CLASSES ADD ARGUMENTS TO CLASS
class Structure(metaclass=StructMeta):
	_fields = []
	def __init__(self, *args, **kwargs):
		print("Call Structure.__init__")
		bound = self.__signature__.bind(*args, **kwargs)
		for name, val in bound.arguments.items():
			setattr(self, name, val)
	
	

class Stock(Structure):
	_fields = ['name', 'shares', 'price']
	shares = Descriptor('shares')



print("\nYay time for the driver code\nS TIME")
s = Stock("GOOG", 12, 20)

print("\nDEBUGGING")
print(s.shares)
s.shares = 30
del s.shares