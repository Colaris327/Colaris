class test_slot(object):
    __slot__ = ('x', 'y')
    def printHello(self):
        print('hello!')
    
class test(object):
    def printHello(self):
        print('hello')

print(dir(test_slot)) 
print(dir(test)) 
print ('**************************************')
ts=test_slot()
t=test()
print(dir(ts)) 
print(dir(t)) 
print('***************************************')
ts.x=11 
t.x=12 
print(ts.x,t.x)
ts.y=22 
t.y=23  
print(ts.y,t.y)
# ts.z=33 # error, you can only use variables in __slot__
t.z=34 
print(t.z)