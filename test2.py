class ValidationError:
	pass


class Field:
	def __new__(cls, names, bases, dct):
		x = super().__new__(cls, names, bases, dct)
		x.blank = None
		x.default = None
		return x


class CharField(Field):
	def __init__(self, max_length=None):
		self.max_length = max_length


class IntegerField(Field):
	def __init__(self, min_value=None, max_value=None):
		self.min_value = min_value
		self.max_value = max_value


class BooleanField(Field):
	pass


class DateTimeField(Field):
	def __init__(self, auto_now=False):
		self.auto_now = auto_now


class EmailField(Field):
	def __init__(self, min_length=0, max_length=None):
		self.min_length = min_length
		self.max_length = max_length


class Model:
	def validate(self):
		pass
	
	def __new__(cls, *args, **kwargs):
		x = super().__new__(cls, *args, **kwargs)


class User(Model):
	first_name = CharField(max_length=30)
	last_name = CharField(max_length=50)
	email = EmailField()
	is_verified = BooleanField(default=False)
	date_joined = DateTimeField(auto_now=True)
	age = IntegerField(min_value=5, max_value=120, blank=True)


user1 = User(first_name='Liam', last_name='Smith', email='liam@example.com')
user1.validate()

print(user1.date_joined)  # prints date and time when the instance was created
print(user1.is_verified)  # prints False (default value)

user1.age = 256
user1.validate()  # raises ValidationError - age is out of range

user2 = User()
user2.validate()  # raises ValidationError - first three fields are missing and mandatory