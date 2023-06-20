import codecs
with codecs.open('GitaText.txt', encoding='utf-8') as f:
    for l_no, line in enumerate(f):
        # search string
        if 'translation' in line:
            print('string found in a file')
            print('Line Number:', l_no)
            print('Line:', line)
            # don't look for next lines
            # break