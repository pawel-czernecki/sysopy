import time
import random
from threading import Lock, Thread

class Philosopher:
    def __init__(self, index, left_fork, right_fork):
        self.index = index
        self.left_fork = left_fork
        self.right_fork = right_fork
        self.eat_count = 0

    def eat(self):
        print(f"Filozof {self.index} je. Jadł już {self.eat_count + 1} razy.")
        self.eat_count += 1

    def think(self):
        print(f"Filozof {self.index} myśli.")

    def pick_forks(self, method):
        if method == 1:
            self.pick_forks_method_1()
        elif method == 2:
            self.pick_forks_method_2()

    def release_forks(self):
        self.left_fork.release()
        self.right_fork.release()

    def pick_forks_method_1(self):
        self.left_fork.acquire()
        self.right_fork.acquire()

    def pick_forks_method_2(self):
        if self.index % 2 == 0:
            self.right_fork.acquire()
            self.left_fork.acquire()
        else:
            self.left_fork.acquire()
            self.right_fork.acquire()

def philosopher(index, forks, method):
    left_fork = forks[index]
    right_fork = forks[(index + 1) % len(forks)]
    philosopher = Philosopher(index, left_fork, right_fork)

    while True:
        philosopher.think()
        time.sleep(random.randint(1, 5))

        philosopher.pick_forks(method)
        try:
            philosopher.eat()
        finally:
            philosopher.release_forks()
            time.sleep(random.randint(1, 10))

if __name__ == "__main__":
    import sys

    method = int(sys.argv[1])
    # 1 - simple method
    # 2 - optimised method
    n = int(sys.argv[2])

    forks = [Lock() for _ in range(n)]
    philosophers = []

    for i in range(n):
        philosopher_thread = Thread(target=philosopher, args=(i, forks, method))
        philosopher_thread.start()
        philosophers.append(philosopher_thread)

    for philosopher_thread in philosophers:
        philosopher_thread.join()