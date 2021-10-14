.extern __aeabi_ldivmod,__aeabi_uldivmod,__aeabi_d2lz,__aeabi_d2ulz,__aeabi_l2d,__aeabi_ul2d,__aeabi_f2lz,__aeabi_f2ulz,__aeabi_l2f,__aeabi_ul2f
.text
.thumb

.global s_aeabi_ldivmod
.type s_aeabi_ldivmod,%function
.thumb_func
s_aeabi_ldivmod:
    b __aeabi_ldivmod

.global s_aeabi_uldivmod
.type s_aeabi_uldivmod,%function
.thumb_func
s_aeabi_uldivmod:
    b __aeabi_uldivmod

.global s_aeabi_d2lz
.type s_aeabi_d2lz,%function
.thumb_func
s_aeabi_d2lz:
    b __aeabi_d2lz

.global s_aeabi_d2ulz
.type s_aeabi_d2ulz,%function
.thumb_func
s_aeabi_d2ulz:
    b __aeabi_d2ulz

.global s_aeabi_l2d
.type s_aeabi_l2d,%function
.thumb_func
s_aeabi_l2d:
    b __aeabi_l2d

.global s_aeabi_ul2d
.type s_aeabi_ul2d,%function
.thumb_func
s_aeabi_ul2d:
    b __aeabi_ul2d

.global s_aeabi_f2lz
.type s_aeabi_f2lz,%function
.thumb_func
s_aeabi_f2lz:
    b __aeabi_f2lz

.global s_aeabi_f2ulz
.type s_aeabi_f2ulz,%function
.thumb_func
s_aeabi_f2ulz:
    b __aeabi_f2ulz

.global s_aeabi_l2f
.type s_aeabi_l2f,%function
.thumb_func
s_aeabi_l2f:
    b __aeabi_l2f

.global s_aeabi_ul2f
.type s_aeabi_ul2f,%function
.thumb_func
s_aeabi_ul2f:
    b __aeabi_ul2f
