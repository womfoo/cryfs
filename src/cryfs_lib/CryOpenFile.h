#pragma once
#ifndef CRYFS_LIB_CRYOPENFILE_H_
#define CRYFS_LIB_CRYOPENFILE_H_

#include "fspp/fs_interface/OpenFile.h"
#include "fspp/utils/macros.h"

namespace cryfs {
class CryDevice;

class CryOpenFile: public fspp::OpenFile {
public:
  CryOpenFile(const CryDevice *device, const boost::filesystem::path &path, int flags);
  virtual ~CryOpenFile();

  void stat(struct ::stat *result) const override;
  void truncate(off_t size) const override;
  int read(void *buf, size_t count, off_t offset) override;
  void write(const void *buf, size_t count, off_t offset) override;
  void flush() override;
  void fsync() override;
  void fdatasync() override;

private:
  int _descriptor;

  DISALLOW_COPY_AND_ASSIGN(CryOpenFile);
};

} /* namespace cryfs */

#endif
