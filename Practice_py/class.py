class student(object):

    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def study(self, course_name):
        print('%s is studying at %s.' % (self.name, course_name))
    
    def watch_movie(self):
        if self.age < 18:
            print('%s is watching pepepig.' % (self.name))
        else:
            print('%s is watching spongebob.' % (self.name))

def main():
    stu1 = student('Wang', 20)
    stu1.study('python')
    stu1.watch_movie()

if __name__ == '__main__':
    main()
