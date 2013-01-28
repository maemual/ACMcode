#!/usr/bin/python
#coding=utf-8
import os
from optparse import OptionParser

EXT = ['.java','.py','.c','.cpp','.pyw']

def get_files(dir):
    l = []
    for root, dirs, files in os.walk(dir):
        l.extend([os.path.join(root, name) for name in files])
    return l

def fun():
    MSG_USAGE = u'wcx [-l] arg0,arg1...'
    optParser = OptionParser(MSG_USAGE)
    optParser.add_option("-l","--lines",action="store_true",dest="linesFlag",
            help=u"统计代码行数")
    optParser.add_option("-w","--words",action="store_true",dest="wordsFlag",
            help=u"统计单词计数")
    optParser.add_option("-c","--bytes",action="store_true",dest="bytesFlag",
            help=u"统计字节计数")
    optParser.add_option("-m","--chars",action="store_true",dest="charsFlag",
            help=u"统计字符计数")
    option, args = optParser.parse_args()

    params = []
    for p in args:
        if os.path.isdir(p):
            params.extend(get_files(p))
        else:
            params.append(p)
    params = ["'"+p+"'" for p in params if os.path.splitext(p)[1] in EXT]

    if option.linesFlag:
        result = os.popen("wc -l %s"%" ".join(params)).read()
        print result
    elif option.wordsFlag:
        result = os.popen("wc -w %s"%" ".join(params)).read()
        print result
    elif option.bytesFlag:
        result = os.popen("wc -c %s"%" ".join(params)).read()
        print result
    elif option.charsFlag:
        result = os.popen("wc -m %s"%" ".join(params)).read()
        print result

if __name__== '__main__':
    fun()
