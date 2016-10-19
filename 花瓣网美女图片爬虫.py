import re
import urllib.request

def getHtml(url):
    page = urllib.request.urlopen(url)
    html = page.read()
    return html


def getImg(html):
    html = html.decode('utf-8')
    #print(html)
    reg='"key":"(.{45}\-.{6})", "type"'
    imglist = re.findall(reg,html, re.S)
    #print(imglist)
    url=""
    for imgurl in imglist:
        url="http://img.hb.aicdn.com/"+imgurl+"_fw658"
        print(url)
        urllib.request.urlretrieve(url, '%s.jpg' % imgurl)
        url=""
    
    


Imghtml = getHtml('http://huaban.com/favorite/beauty/')
getImg(Imghtml)
