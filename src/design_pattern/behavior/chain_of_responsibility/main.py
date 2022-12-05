#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 1. 一开始，只对用户ID、密码验证有效性
# 2. 然后，需求扩充，对请求源的IP做过滤
# 3. 然后，需求扩充，对请求的频率做过滤
# 4. ...

def check_user_passwd(user, passwd):
    if user == 'root':
        if passwd == 'root':
            return True
        else:
            return False
    elif user == 'admin':
        if passwd == 'admin':
            return True
        else:
            return False
    else:
        return False

def process(user, passwd):
    if check_user_passwd(user, passwd):
        print(f'{user} Login success')


def process_2(user, passwd, ip):
    if check_user_passwd(user, passwd):
        if ip == '10.10.200.1':
            print(f'{user} {ip} Login success')
        else:
            print(f'{user} {ip} Login failed')

if __name__ == '__main__':
    process('root', 'root')
    process_2('root', 'root', '10.11.200.1')
