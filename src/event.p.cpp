// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: event.proto

#include "event.pb.hpp"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
class EventDefaultTypeInternal
{
public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<Event> _instance;
} _Event_default_instance_;
static void InitDefaultsscc_info_Event_event_2eproto()
{
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void *ptr = &::_Event_default_instance_;
    new (ptr)::Event();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::Event::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_Event_event_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_Event_event_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_event_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const **file_level_enum_descriptors_event_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const **file_level_service_descriptors_event_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_event_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    ~0u, // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::Event, _internal_metadata_),
    ~0u, // no _extensions_
    ~0u, // no _oneof_case_
    ~0u, // no _weak_field_map_
    PROTOBUF_FIELD_OFFSET(::Event, action_),
    PROTOBUF_FIELD_OFFSET(::Event, devname_),
    PROTOBUF_FIELD_OFFSET(::Event, vendor_),
    PROTOBUF_FIELD_OFFSET(::Event, model_),
    PROTOBUF_FIELD_OFFSET(::Event, size_),
    PROTOBUF_FIELD_OFFSET(::Event, partitions_),
    PROTOBUF_FIELD_OFFSET(::Event, type_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    {0, -1, sizeof(::Event)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const *const file_default_instances[] = {
    reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message *>(&::_Event_default_instance_),
};

const char descriptor_table_protodef_event_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
    "\n\013event.proto\"w\n\005Event\022\016\n\006action\030\001 \001(\t\022\017"
    "\n\007devname\030\002 \001(\t\022\016\n\006vendor\030\003 \001(\t\022\r\n\005model"
    "\030\004 \001(\t\022\014\n\004size\030\005 \001(\005\022\022\n\npartitions\030\006 \001(\005"
    "\022\014\n\004type\030\007 \001(\tb\006proto3";
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable *const descriptor_table_event_2eproto_deps[1] = {};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase *const descriptor_table_event_2eproto_sccs[1] = {
    &scc_info_Event_event_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_event_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_event_2eproto = {
    false,
    false,
    descriptor_table_protodef_event_2eproto,
    "event.proto",
    142,
    &descriptor_table_event_2eproto_once,
    descriptor_table_event_2eproto_sccs,
    descriptor_table_event_2eproto_deps,
    1,
    0,
    schemas,
    file_default_instances,
    TableStruct_event_2eproto::offsets,
    file_level_metadata_event_2eproto,
    1,
    file_level_enum_descriptors_event_2eproto,
    file_level_service_descriptors_event_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_event_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_event_2eproto)), true);

// ===================================================================

void Event::InitAsDefaultInstance()
{
}
class Event::_Internal
{
public:
};

Event::Event(::PROTOBUF_NAMESPACE_ID::Arena *arena)
    : ::PROTOBUF_NAMESPACE_ID::Message(arena)
{
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:Event)
}
Event::Event(const Event &from)
    : ::PROTOBUF_NAMESPACE_ID::Message()
{
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  action_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_action().empty())
  {
    action_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_action(),
                GetArena());
  }
  devname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_devname().empty())
  {
    devname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_devname(),
                 GetArena());
  }
  vendor_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_vendor().empty())
  {
    vendor_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_vendor(),
                GetArena());
  }
  model_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_model().empty())
  {
    model_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_model(),
               GetArena());
  }
  type_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_type().empty())
  {
    type_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_type(),
              GetArena());
  }
  ::memcpy(&size_, &from.size_,
           static_cast<size_t>(reinterpret_cast<char *>(&partitions_) -
                               reinterpret_cast<char *>(&size_)) +
               sizeof(partitions_));
  // @@protoc_insertion_point(copy_constructor:Event)
}

void Event::SharedCtor()
{
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_Event_event_2eproto.base);
  action_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  devname_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  vendor_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  model_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  type_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&size_, 0, static_cast<size_t>(reinterpret_cast<char *>(&partitions_) - reinterpret_cast<char *>(&size_)) + sizeof(partitions_));
}

Event::~Event()
{
  // @@protoc_insertion_point(destructor:Event)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void Event::SharedDtor()
{
  GOOGLE_DCHECK(GetArena() == nullptr);
  action_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  devname_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  vendor_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  model_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  type_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void Event::ArenaDtor(void *object)
{
  Event *_this = reinterpret_cast<Event *>(object);
  (void)_this;
}
void Event::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena *)
{
}
void Event::SetCachedSize(int size) const
{
  _cached_size_.Set(size);
}
const Event &Event::default_instance()
{
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_Event_event_2eproto.base);
  return *internal_default_instance();
}

void Event::Clear()
{
  // @@protoc_insertion_point(message_clear_start:Event)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void)cached_has_bits;

  action_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  devname_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  vendor_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  model_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  type_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&size_, 0, static_cast<size_t>(reinterpret_cast<char *>(&partitions_) - reinterpret_cast<char *>(&size_)) + sizeof(partitions_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char *Event::_InternalParse(const char *ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext *ctx)
{
#define CHK_(x)                     \
  if (PROTOBUF_PREDICT_FALSE(!(x))) \
  goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena *arena = GetArena();
  (void)arena;
  while (!ctx->Done(&ptr))
  {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3)
    {
    // string action = 1;
    case 1:
      if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10))
      {
        auto str = _internal_mutable_action();
        ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
        CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Event.action"));
        CHK_(ptr);
      }
      else
        goto handle_unusual;
      continue;
    // string devname = 2;
    case 2:
      if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18))
      {
        auto str = _internal_mutable_devname();
        ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
        CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Event.devname"));
        CHK_(ptr);
      }
      else
        goto handle_unusual;
      continue;
    // string vendor = 3;
    case 3:
      if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26))
      {
        auto str = _internal_mutable_vendor();
        ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
        CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Event.vendor"));
        CHK_(ptr);
      }
      else
        goto handle_unusual;
      continue;
    // string model = 4;
    case 4:
      if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34))
      {
        auto str = _internal_mutable_model();
        ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
        CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Event.model"));
        CHK_(ptr);
      }
      else
        goto handle_unusual;
      continue;
    // int32 size = 5;
    case 5:
      if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 40))
      {
        size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
        CHK_(ptr);
      }
      else
        goto handle_unusual;
      continue;
    // int32 partitions = 6;
    case 6:
      if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48))
      {
        partitions_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
        CHK_(ptr);
      }
      else
        goto handle_unusual;
      continue;
    // string type = 7;
    case 7:
      if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 58))
      {
        auto str = _internal_mutable_type();
        ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
        CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "Event.type"));
        CHK_(ptr);
      }
      else
        goto handle_unusual;
      continue;
    default:
    {
    handle_unusual:
      if ((tag & 7) == 4 || tag == 0)
      {
        ctx->SetLastTag(tag);
        goto success;
      }
      ptr = UnknownFieldParse(tag,
                              _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
                              ptr, ctx);
      CHK_(ptr != nullptr);
      continue;
    }
    } // switch
  } // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8 *Event::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8 *target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream *stream) const
{
  // @@protoc_insertion_point(serialize_to_array_start:Event)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void)cached_has_bits;

  // string action = 1;
  if (this->action().size() > 0)
  {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        this->_internal_action().data(), static_cast<int>(this->_internal_action().length()),
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
        "Event.action");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_action(), target);
  }

  // string devname = 2;
  if (this->devname().size() > 0)
  {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        this->_internal_devname().data(), static_cast<int>(this->_internal_devname().length()),
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
        "Event.devname");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_devname(), target);
  }

  // string vendor = 3;
  if (this->vendor().size() > 0)
  {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        this->_internal_vendor().data(), static_cast<int>(this->_internal_vendor().length()),
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
        "Event.vendor");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_vendor(), target);
  }

  // string model = 4;
  if (this->model().size() > 0)
  {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        this->_internal_model().data(), static_cast<int>(this->_internal_model().length()),
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
        "Event.model");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_model(), target);
  }

  // int32 size = 5;
  if (this->size() != 0)
  {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(5, this->_internal_size(), target);
  }

  // int32 partitions = 6;
  if (this->partitions() != 0)
  {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(6, this->_internal_partitions(), target);
  }

  // string type = 7;
  if (this->type().size() > 0)
  {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        this->_internal_type().data(), static_cast<int>(this->_internal_type().length()),
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
        "Event.type");
    target = stream->WriteStringMaybeAliased(
        7, this->_internal_type(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields()))
  {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Event)
  return target;
}

size_t Event::ByteSizeLong() const
{
  // @@protoc_insertion_point(message_byte_size_start:Event)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void)cached_has_bits;

  // string action = 1;
  if (this->action().size() > 0)
  {
    total_size += 1 +
                  ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                      this->_internal_action());
  }

  // string devname = 2;
  if (this->devname().size() > 0)
  {
    total_size += 1 +
                  ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                      this->_internal_devname());
  }

  // string vendor = 3;
  if (this->vendor().size() > 0)
  {
    total_size += 1 +
                  ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                      this->_internal_vendor());
  }

  // string model = 4;
  if (this->model().size() > 0)
  {
    total_size += 1 +
                  ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                      this->_internal_model());
  }

  // string type = 7;
  if (this->type().size() > 0)
  {
    total_size += 1 +
                  ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                      this->_internal_type());
  }

  // int32 size = 5;
  if (this->size() != 0)
  {
    total_size += 1 +
                  ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
                      this->_internal_size());
  }

  // int32 partitions = 6;
  if (this->partitions() != 0)
  {
    total_size += 1 +
                  ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
                      this->_internal_partitions());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields()))
  {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Event::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message &from)
{
  // @@protoc_insertion_point(generalized_merge_from_start:Event)
  GOOGLE_DCHECK_NE(&from, this);
  const Event *source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<Event>(
          &from);
  if (source == nullptr)
  {
    // @@protoc_insertion_point(generalized_merge_from_cast_fail:Event)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  }
  else
  {
    // @@protoc_insertion_point(generalized_merge_from_cast_success:Event)
    MergeFrom(*source);
  }
}

void Event::MergeFrom(const Event &from)
{
  // @@protoc_insertion_point(class_specific_merge_from_start:Event)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void)cached_has_bits;

  if (from.action().size() > 0)
  {
    _internal_set_action(from._internal_action());
  }
  if (from.devname().size() > 0)
  {
    _internal_set_devname(from._internal_devname());
  }
  if (from.vendor().size() > 0)
  {
    _internal_set_vendor(from._internal_vendor());
  }
  if (from.model().size() > 0)
  {
    _internal_set_model(from._internal_model());
  }
  if (from.type().size() > 0)
  {
    _internal_set_type(from._internal_type());
  }
  if (from.size() != 0)
  {
    _internal_set_size(from._internal_size());
  }
  if (from.partitions() != 0)
  {
    _internal_set_partitions(from._internal_partitions());
  }
}

void Event::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message &from)
{
  // @@protoc_insertion_point(generalized_copy_from_start:Event)
  if (&from == this)
    return;
  Clear();
  MergeFrom(from);
}

void Event::CopyFrom(const Event &from)
{
  // @@protoc_insertion_point(class_specific_copy_from_start:Event)
  if (&from == this)
    return;
  Clear();
  MergeFrom(from);
}

bool Event::IsInitialized() const
{
  return true;
}

void Event::InternalSwap(Event *other)
{
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  action_.Swap(&other->action_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  devname_.Swap(&other->devname_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  vendor_.Swap(&other->vendor_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  model_.Swap(&other->model_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  type_.Swap(&other->type_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Event, partitions_) + sizeof(Event::partitions_) - PROTOBUF_FIELD_OFFSET(Event, size_)>(
      reinterpret_cast<char *>(&size_),
      reinterpret_cast<char *>(&other->size_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Event::GetMetadata() const
{
  return GetMetadataStatic();
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template <>
PROTOBUF_NOINLINE ::Event *Arena::CreateMaybeMessage<::Event>(Arena *arena)
{
  return Arena::CreateMessageInternal<::Event>(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
