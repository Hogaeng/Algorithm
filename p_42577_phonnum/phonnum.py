def solution(phone_book):
    """
    answer = True
    for s in phone_book:
        tmp=""
        for letter in s:
            tmp+=letter
            if tmp in phone_book:
                if tmp != s:
                    answer=False
    return answer
    """
    answer = True
    di={}
    for s in phone_book:
        di[s]=1
    for s in phone_book:
        tmp=""
        for letter in s:
            tmp+=letter
            if tmp in di:
                if tmp != s:
                    answer=False
    return answer
