import imaplib
import email
from email.header import decode_header
import webbrowser
import os

username = "gauranshkhurana0005@gmail.com"
password = "Thisisavery$ecurepa55word"

imap = imaplib.IMAP4_SSL("imap.gmail.com")
imap.login(username, password)
print(imap.list())
status, messages = imap.select("Anil Khurana")

N = 3