############### work.py ###############
class Porsche(object):
    def __init__(self, owner, speed):
        self._owner = owner
        self._speed = speed

    def drive(self):
        return f"{self._owner} is driving a Porsche at {self._speed} km/h."

    @property
    def owner(self):
        return self._owner

    @property
    def speed(self):
        return self._speed

    @owner.setter
    def owner(self, value):
        if isinstance(value, str):
            self._owner = value
        else:
            raise TypeError('owner must be a string')

    @speed.setter
    def speed(self, value):
        if isinstance(value, float):
            self._speed = value
        else:
            raise TypeError('speed must be a float')

# class Ferrari(object):
# class Lamborghini(object):
# class Bugatti(object):
# class Koenigsegg(object):
# class Mclaren(object):
# class Pagani(object):
# class AstonMartin(object):
# class RollsRoyce(object):
# class Bentley(object):
# class Audi(object):
# class BMW(object):
# class Benz(object):
# class Mercedes(object):
# class Volkswagen(object):
# class Ford(object):
# class Chevrolet(object):
# class Dodge(object):
# class Chrysler(object):

def Work():
    porsche = Porsche('Hans', 330.0)
    print(porsche.drive())
    # ferrari = Ferrari('Henry', 341.0)
    # ...
