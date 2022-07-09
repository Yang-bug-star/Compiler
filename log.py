class Log():
  row = None
  col = None
  message = ''


def print_log(log):
  if log.row is not None and log.col is not None:
    print('At %d:%d'%(log.row, log.col))
  print(log.message)
