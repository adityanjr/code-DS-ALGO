
class Singleton(object):
  __instance = None

  def __init__(self):
    print "call"

  @staticmethod
  def get_instance():
    if not Singleton.__instance:
      Singleton.__instance = Singleton()
    return Singleton.__instance

a = Singleton.get_instance()
b = Singleton.get_instance()