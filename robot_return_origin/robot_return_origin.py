DIR = {
    'U': [0, 1],
    'D': [0, -1],
    'R': [1, 0],
    'L': [-1, 0]
}

def does_robot_return_origin(dirs):
    pos = [0, 0]
    for ch in dirs:
        dir = DIR[ch]
        pos[0] += dir[0]
        pos[1] += dir[1]
    return pos == [0, 0]


for dirs in ['UD', 'UR', 'UURRDDLL']:
    print("After '{}' does robot return: {}".format(dirs, does_robot_return_origin(dirs)))
