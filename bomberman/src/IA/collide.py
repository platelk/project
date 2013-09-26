#! /bin/python3.3

def     interCircleRect(rx, ry, rw, rh, cx, cy, cr):
    half = (rw / 2, rh / 2)
    tmp_pos = (math.fabs(cx - rx - half[0]), math.fabs(cy - ry - half[1]))
    crange = (half[0] + cr, half[1] + cr)
    if tmp_pos[0] > crange[0] or tmp_pos[1] > crange[1]:
        return (False)
    if tmp_pos[0] <= half[0] or tmp_pos[1] <= half[1]:
        return (True)
    corner_range = (tmp_pos[0] - half[0], tmp_pos[1] - half[1])
    corner_range_sq = (corner_range[0]**2, corner_range[1]**2)
    corner_max_range_sq = cr**2
    return (corner_range_sq[0] + corner_range_sq[1] <= corner_max_range_sq)

def     interCircleCircle(c1, r1, c2, r2):
    return (math.fabs(math.sqrt((c2[0] - c1[0])**2 + (c2[1] - c1[1])**2)) < r1 + r2)

def     interCirclePoint(pos, cpos, radius):
    return (((pos[0] - cpos[0])**2 + (pos[1] - cpos[1])**2) < radius**2)
