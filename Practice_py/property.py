class Person(object):
    def __init__(self, name, age):
        self._name = name
        self._age = age
    
    @property
    def age(self):
        return self._age

    @property
    def name(self):
        return self._name

    @age.setter
    def age(self, age):
        self._age = age

    def play(self):
        if self._age < 16:
            print('%s is playing maplestory.' % (self._name))
        else:
            print('%s is playing GTAV' % (self._name))

def main():
    person = Person('Josh', 15)
    person.play()
    person.age = 22
    person.play()
    #person.name = 'Rick' #Trace back

if __name__ == '__main__':
    main()