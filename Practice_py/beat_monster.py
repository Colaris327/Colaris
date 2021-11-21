from abc import ABCMeta, abstractmethod
from random import randint, randrange

class Fighter(object):
    __slots__ = ('_name', '_hp')

    def __init__ (self, name, hp):
        self._name = name
        self._hp = hp
    
    @property
    def name(self):
        return self._name

    @property
    def hp(self):
        return self._hp

    @hp.setter
    def name(self, hp):
        self._hp = hp if hp >= 0 else 0
    
    @property
    def alive(self):
        return self._hp > 0

    @abstractmethod
    def attack(self, other):
        pass

class Ultarman(Fighter):
    __slots__ = ('_name', '_hp', '_mp')

    def __init__(self, name, hp, mp):
        super().__init__(name, hp)
        self._mp = mp

    def attack(self, other):
        other._hp -= randint(15, 25)

    def huge_attack(self, other):
        if self._mp >= 50:
            self._mp -= 50
            injury = other._hp * 3 // 4
            injury = injury if injury >= 50 else 50
            other._hp -= injury
            return True
        else:
            self.attack(other)
            return False

    def magic_attack(self, others):
        if self._mp >= 20:
            self._mp -= 20
            for other in others:
                if other.alive:
                    other._hp -= randint(15, 25)
            return True
        else:
            return False

    def resume(self):
        bottle = randint(1, 10)
        self._mp += bottle
        return bottle

    def __str__(self):
        return '-----Ultraman-----\n' + \
            'HP : %s\n' % (self._hp) + \
            'MP : %s\n' % (self._mp)

class Monster(Fighter):
    __slots__ = ('_name', '_hp')

    def __init__(self, name, hp):
        super().__init__(name, hp)

    def attack(self, other):
        other._hp -= randint(10, 20)

    def __str__(self):
        return '-----Moster %s-----\n' % (self._name) + \
            'HP : %s\n' % (self._hp)

def is_any_alive(monsters):
    for monster in monsters:
        if monster.alive:
            return True
    return False

def select_one(monsters):
    monsters_len = len(monsters)
    while True:
        index = randrange(monsters_len)
        monster = monsters[index]
        if monster.alive:
            return monster

def display_info(ultraman, monsters):
    print(ultraman)
    for monster in monsters:
        print(monster, end=' ')

def main():
    u = Ultarman('Wang', 1000, 120)
    m1 = Monster('Money', 250)
    m2 = Monster('House', 500)
    m3 = Monster('MasterDegree', 750)
    ms = [m1, m2, m3]
    round = 1
    while u.alive and is_any_alive(ms):
        print('====== Round %02d ======' % (round))
        m = select_one(ms)
        skill = randint(1, 10)
        if skill <= 6:
            print('%s use attack to %s' % (u._name, m._name))
            u.attack(m)
            print('%s resume %d MP' % (u._name, u.resume()))
        elif skill <= 9:
            if u.magic_attack(ms):
                print('%s use magic attack to monsters' % (u._name))
            else:
                print('%s fail to use magic attack' % (u._name))
        else:
            if u.huge_attack(m):
                print('%s use huge attack to %s' %(u._name, m._name))
            else:
                print('%s use attack to %s' % (u._name, m._name))
                print('%s resume %d MP' % (u.name, u._mp))
        if m.alive:
            m.attack(u)
            print('%s attack to %s' % (m._name, u._name))
        display_info(u, ms)
        round += 1
    print('====== END ======')
    if u.alive:
        print('Ultraman wins!!')
    else:
        print('Monsters win!!')

if __name__ == '__main__':
    main()