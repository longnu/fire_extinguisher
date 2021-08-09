from pushbullet import Pushbullet
 
api_key = 'o.OC1qS9MhYZhJEhOGrBSa2bILCnFotNyI'
pb = Pushbullet(api_key)
print(pb.devices) #Device 표시
 
device = pb.devices[0] #디바이스 설정
 
msg_frame = '''
{}
강의실 3층 소화기 압력이 불량입니다! 확인해주세요!
'''
 
push = pb.push_sms(device, '+821028738300', msg_frame.format('알림'))
