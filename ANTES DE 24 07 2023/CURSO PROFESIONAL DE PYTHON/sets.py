#[1, 1, 2, 2, 4] -> [1, 2, 4]

def remove_duplicates(some_list):
    whithout_duplicates=[]
    for element in some_list:
        if element not in whithout_duplicates:
            whithout_duplicates.append(element)
    return whithout_duplicates


def run():
    random_list=[1, 1, 2, 2, 4]
    print(remove_duplicates(random_list))

    
if __name__=='__main__':
    run()