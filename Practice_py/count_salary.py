from abc import ABCMeta, abstractmethod

class Employee(object):
    
    def __init__ (self, name):
        self._name = name

    @property
    def name(self):
        return self._name

    @abstractmethod
    def get_salary(self):
        pass

class Programer(Employee):
    
    def __int__(self, name, working_hours = 0):
        super().__init__(name)
        self._working_hours = working_hours

    @property
    def working_hours(self):
        return self._working_hours

    @working_hours.setter
    def working_hours(self, working_hours):
        self._working_hours = working_hours if working_hours > 0 else 0

    def get_salary(self):
        return 150 * self._working_hours

class Manager(Employee):
    
    def get_salary(self):
        return 15000

class Salesman(Employee):
    def __init__(self, name, sales = 0):
        super().__init__(name)
        self._sales = sales
    
    @property
    def sales(self):
        return self._sales

    @sales.setter
    def sales(self, sales):
        self._sales = sales if sales > 0 else 0
    
    def get_salary(self):
        return 1200 + 0.05 * self._sales

def main():
    emps = [Programer('Josh'), Programer('Yaki'), Programer('Wang'),
            Salesman('Hao'), Salesman('Yong'), Manager('Chung')]
    for emp in emps:
        if isinstance(emp, Programer):
            emp._working_hours = int(input('Enter the working hours of %s : ' %(emp._name)))
        elif isinstance(emp, Salesman):
            emp._sales = float(input('Enter the sales of %s : ' % (emp.name)))
        print('The salary %s get this month is %s' % (emp._name, emp.get_salary()))

if __name__ == '__main__':
    main()