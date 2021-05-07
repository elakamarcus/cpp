#!/bin/python3

import sys, base64, requests

def authit(url, user, password):
    url = "https://" + serverAddr + "/phoenix/rest/"
    auth = "Basic " + base64.b64encode(user + ":" + password)

