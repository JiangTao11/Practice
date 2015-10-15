
from flask import Flask
app = Flask(__name__)
 
#发信邮箱配置信息
app.config['MAIL_SERVER'] = 'smtp.gmail.com'
app.config['MAIL_PORT'] = 465
app.config['MAIL_USE_TLS'] = False
app.config['MAIL_USE_SSL'] = True
app.config['MAIL_USERNAME'] = 'jiangtao19993@gmail.com'
app.config['MAIL_PASSWORD'] = 'Password'
app.config['ADMINS'] = '15202444695@163.com'
 
 
#初始化Mail对象连接smtp服务器
from flask.ext.mail import Mail
mail = Mail(app)
 
 
#发邮件
from flask.ext.mail import Message
msg = Message('test subject', sender='jiangtao19993@gmail.com', recipients=['15202444695@163.com'])
msg.body = 'text body111'
msg.html = '<b>HTML</b> body'
 
with app.app_context():
	mail.send(msg)