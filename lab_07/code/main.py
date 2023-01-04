dict = {'очень мало': [1, 5], 'мало': [5, 10], 'не очень мало': [10, 20], 'средне': [20, 60],
        'не очень много': [60, 120],  'много': [120, 300], 'очень много': [300-1000]}

object = ['шахматы',
            'шахматная партия',
            'шахматной партии', 
            'шахмат',
            'длительность партии', 
            'игры в шахматы',
            'шахматная']

term =   ["очень мало",
          "мало",
          "не очень мало",
          "средне",
          "не очень много",
          "много",
          "очень много"]

MSG =   "Вводите вопрос с маленькой буквы и без орфографических ошибок:\n"

def print_hours(arr):
    if len(arr) == 1:
        print("Ответ: %d" % (arr[0]))
    else:
        print("Ответ: %d - %d" % (arr[0], arr[len(arr) - 1]))

def print_term(str):
    print("Ответ: %s" % (str))

def main():
    answer = input(MSG)

    if any(elem in answer for elem in object):
        for elem in term:
            if elem in answer and not any(ch.isdigit() for ch in answer):
                print_hours(dict.get(elem))
                return

        for elem in answer:
            if all(ch.isdigit() for ch in elem):
                for k, v in dict.items():
                    if int(elem) in v:
                        print_term(k)
                        return

        print("\nНевозможно ответить на вопрос, хотя он подходит по тематике\n")

    else:
        print("\nВаш вопрос не содержит рассматриваемый объект")

if __name__ == "__main__":
    main()
