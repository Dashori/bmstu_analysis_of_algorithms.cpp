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
