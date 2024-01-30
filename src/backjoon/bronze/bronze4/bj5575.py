for _ in range(3):
    sh, sm, ss, eh, em, es = map(int, input().split())
    start_sec = sh * 3600 + sm * 60 + ss
    end_sec = eh * 3600 + em * 60 + es
    work_sec = end_sec - start_sec
    wh, wm, ws = work_sec // 3600, (work_sec % 3600) // 60, (work_sec % 3600) % 60
    print(wh, wm, ws)