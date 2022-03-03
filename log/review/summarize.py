import os
import sys
import datetime

def date(day):
  return day.strftime("%Y-%m-%d")

today = datetime.date.today()
filename = "review_" + date(today) + ".md"

if os.path.isfile(filename):
  print("Review summary exists.")
  sys.exit()

file = open(filename, "w")
for day in [today - datetime.timedelta(days = i) for i in [1, 2, 4, 8, 16, 32]]:
  fn = "../" + date(day) + ".md"
  if os.path.isfile(fn):
    file.write(f"""# [{date(day)}]({fn})\n\n""")
file.close()

print("Review summary generated.")
