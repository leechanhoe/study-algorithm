def solution(play_time, adv_time, logs):
    from collections import defaultdict

    def convert(t):
        return int(t[:2]) * 3600 + int(t[3:5]) * 60 + int(t[-2:])

    adv = convert(adv_time)
    play = convert(play_time)
    t = [0] * (play + 1)

    log = defaultdict(int)
    for l in logs:
        s = convert(l[:8])
        e = convert(l[-8:])
        log[s] += 1
        log[e] -= 1

    for i in range(play + 1):
        t[i] = t[i - 1]
        if i in log:
            t[i] += log[i]

    now = 0
    max_ = 0
    ans = 0
    for i in range(1, play + 1):
        now += t[i - 1]
        if i > adv:
            now -= t[i - adv - 1]

        if i >= adv and max_ < now:
            max_ = now
            ans = i - adv

    answer = (
        str(ans // 3600).zfill(2)
        + ":"
        + str(ans % 3600 // 60).zfill(2)
        + ":"
        + str(ans % 60).zfill(2)
    )
    return answer
