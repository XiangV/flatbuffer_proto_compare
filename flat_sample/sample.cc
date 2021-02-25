#include "sample_generated.h" // already include flatbuffers/flatbuffers.h"

using namespace xiangv::sample;

int main() {
  // 两种创建方法
  {
    flatbuffers::FlatBufferBuilder fbb;
    auto uid = ClientUniqID(489, 1086);
    auto builder = ClientReportBuilder(fbb);
    builder.add_count(108);
    builder.add_type(DBAccessType::DBAccessType_Get);
    builder.add_cost(11000);
    builder.add_uid(&uid);
    builder.add_info(fbb.CreateString("sample"));
    auto client_report = builder.Finish();
    fbb.Finish(client_report);
    auto detached_buffer = fbb.Release();
    // auto result = fbb.GetBufferPointer();
    // uint32_t size = fbb.GetSize();
  }

  {
    flatbuffers::FlatBufferBuilder fbb;
    auto uid = ClientUniqID(489, 1086);
    auto info = fbb.CreateString("sample"); 
    auto client_report = CreateClientReport(fbb, &uid, DBAccessType_Get,
        info, 108, 11000);
    /// buffer ptr and its length
    char* result = fbb.GetBufferPointer();
    uint32_t size = fbb.GetSize();
  }
}
