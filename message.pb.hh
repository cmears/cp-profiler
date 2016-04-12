// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef PROTOBUF_message_2eproto__INCLUDED
#define PROTOBUF_message_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace message {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_message_2eproto();
void protobuf_AssignDesc_message_2eproto();
void protobuf_ShutdownFile_message_2eproto();

class Node;

enum Node_MsgType {
  Node_MsgType_NODE = 0,
  Node_MsgType_DONE = 1,
  Node_MsgType_START = 2
};
bool Node_MsgType_IsValid(int value);
const Node_MsgType Node_MsgType_MsgType_MIN = Node_MsgType_NODE;
const Node_MsgType Node_MsgType_MsgType_MAX = Node_MsgType_START;
const int Node_MsgType_MsgType_ARRAYSIZE = Node_MsgType_MsgType_MAX + 1;

const ::google::protobuf::EnumDescriptor* Node_MsgType_descriptor();
inline const ::std::string& Node_MsgType_Name(Node_MsgType value) {
  return ::google::protobuf::internal::NameOfEnum(
    Node_MsgType_descriptor(), value);
}
inline bool Node_MsgType_Parse(
    const ::std::string& name, Node_MsgType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Node_MsgType>(
    Node_MsgType_descriptor(), name, value);
}
enum Node_NodeStatus {
  Node_NodeStatus_SOLVED = 0,
  Node_NodeStatus_FAILED = 1,
  Node_NodeStatus_BRANCH = 2,
  Node_NodeStatus_UNDETERMINED = 3,
  Node_NodeStatus_STOP = 4,
  Node_NodeStatus_UNSTOP = 5,
  Node_NodeStatus_SKIPPED = 6,
  Node_NodeStatus_MERGING = 7
};
bool Node_NodeStatus_IsValid(int value);
const Node_NodeStatus Node_NodeStatus_NodeStatus_MIN = Node_NodeStatus_SOLVED;
const Node_NodeStatus Node_NodeStatus_NodeStatus_MAX = Node_NodeStatus_MERGING;
const int Node_NodeStatus_NodeStatus_ARRAYSIZE = Node_NodeStatus_NodeStatus_MAX + 1;

const ::google::protobuf::EnumDescriptor* Node_NodeStatus_descriptor();
inline const ::std::string& Node_NodeStatus_Name(Node_NodeStatus value) {
  return ::google::protobuf::internal::NameOfEnum(
    Node_NodeStatus_descriptor(), value);
}
inline bool Node_NodeStatus_Parse(
    const ::std::string& name, Node_NodeStatus* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Node_NodeStatus>(
    Node_NodeStatus_descriptor(), name, value);
}
// ===================================================================

class Node : public ::google::protobuf::Message {
 public:
  Node();
  virtual ~Node();

  Node(const Node& from);

  inline Node& operator=(const Node& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Node& default_instance();

  void Swap(Node* other);

  // implements Message ----------------------------------------------

  Node* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Node& from);
  void MergeFrom(const Node& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef Node_MsgType MsgType;
  static const MsgType NODE = Node_MsgType_NODE;
  static const MsgType DONE = Node_MsgType_DONE;
  static const MsgType START = Node_MsgType_START;
  static inline bool MsgType_IsValid(int value) {
    return Node_MsgType_IsValid(value);
  }
  static const MsgType MsgType_MIN =
    Node_MsgType_MsgType_MIN;
  static const MsgType MsgType_MAX =
    Node_MsgType_MsgType_MAX;
  static const int MsgType_ARRAYSIZE =
    Node_MsgType_MsgType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  MsgType_descriptor() {
    return Node_MsgType_descriptor();
  }
  static inline const ::std::string& MsgType_Name(MsgType value) {
    return Node_MsgType_Name(value);
  }
  static inline bool MsgType_Parse(const ::std::string& name,
      MsgType* value) {
    return Node_MsgType_Parse(name, value);
  }

  typedef Node_NodeStatus NodeStatus;
  static const NodeStatus SOLVED = Node_NodeStatus_SOLVED;
  static const NodeStatus FAILED = Node_NodeStatus_FAILED;
  static const NodeStatus BRANCH = Node_NodeStatus_BRANCH;
  static const NodeStatus UNDETERMINED = Node_NodeStatus_UNDETERMINED;
  static const NodeStatus STOP = Node_NodeStatus_STOP;
  static const NodeStatus UNSTOP = Node_NodeStatus_UNSTOP;
  static const NodeStatus SKIPPED = Node_NodeStatus_SKIPPED;
  static const NodeStatus MERGING = Node_NodeStatus_MERGING;
  static inline bool NodeStatus_IsValid(int value) {
    return Node_NodeStatus_IsValid(value);
  }
  static const NodeStatus NodeStatus_MIN =
    Node_NodeStatus_NodeStatus_MIN;
  static const NodeStatus NodeStatus_MAX =
    Node_NodeStatus_NodeStatus_MAX;
  static const int NodeStatus_ARRAYSIZE =
    Node_NodeStatus_NodeStatus_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  NodeStatus_descriptor() {
    return Node_NodeStatus_descriptor();
  }
  static inline const ::std::string& NodeStatus_Name(NodeStatus value) {
    return Node_NodeStatus_Name(value);
  }
  static inline bool NodeStatus_Parse(const ::std::string& name,
      NodeStatus* value) {
    return Node_NodeStatus_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required .message.Node.MsgType type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::message::Node_MsgType type() const;
  inline void set_type(::message::Node_MsgType value);

  // optional int32 sid = 2;
  inline bool has_sid() const;
  inline void clear_sid();
  static const int kSidFieldNumber = 2;
  inline ::google::protobuf::int32 sid() const;
  inline void set_sid(::google::protobuf::int32 value);

  // optional int32 pid = 3;
  inline bool has_pid() const;
  inline void clear_pid();
  static const int kPidFieldNumber = 3;
  inline ::google::protobuf::int32 pid() const;
  inline void set_pid(::google::protobuf::int32 value);

  // optional int32 alt = 4;
  inline bool has_alt() const;
  inline void clear_alt();
  static const int kAltFieldNumber = 4;
  inline ::google::protobuf::int32 alt() const;
  inline void set_alt(::google::protobuf::int32 value);

  // optional int32 kids = 5;
  inline bool has_kids() const;
  inline void clear_kids();
  static const int kKidsFieldNumber = 5;
  inline ::google::protobuf::int32 kids() const;
  inline void set_kids(::google::protobuf::int32 value);

  // optional .message.Node.NodeStatus status = 6;
  inline bool has_status() const;
  inline void clear_status();
  static const int kStatusFieldNumber = 6;
  inline ::message::Node_NodeStatus status() const;
  inline void set_status(::message::Node_NodeStatus value);

  // optional int32 restart_id = 7;
  inline bool has_restart_id() const;
  inline void clear_restart_id();
  static const int kRestartIdFieldNumber = 7;
  inline ::google::protobuf::int32 restart_id() const;
  inline void set_restart_id(::google::protobuf::int32 value);

  // optional uint64 time = 8;
  inline bool has_time() const;
  inline void clear_time();
  static const int kTimeFieldNumber = 8;
  inline ::google::protobuf::uint64 time() const;
  inline void set_time(::google::protobuf::uint64 value);

  // optional int32 thread_id = 9;
  inline bool has_thread_id() const;
  inline void clear_thread_id();
  static const int kThreadIdFieldNumber = 9;
  inline ::google::protobuf::int32 thread_id() const;
  inline void set_thread_id(::google::protobuf::int32 value);

  // optional string label = 10;
  inline bool has_label() const;
  inline void clear_label();
  static const int kLabelFieldNumber = 10;
  inline const ::std::string& label() const;
  inline void set_label(const ::std::string& value);
  inline void set_label(const char* value);
  inline void set_label(const char* value, size_t size);
  inline ::std::string* mutable_label();
  inline ::std::string* release_label();
  inline void set_allocated_label(::std::string* label);

  // optional float domain_size = 11;
  inline bool has_domain_size() const;
  inline void clear_domain_size();
  static const int kDomainSizeFieldNumber = 11;
  inline float domain_size() const;
  inline void set_domain_size(float value);

  // optional string solution = 12;
  inline bool has_solution() const;
  inline void clear_solution();
  static const int kSolutionFieldNumber = 12;
  inline const ::std::string& solution() const;
  inline void set_solution(const ::std::string& value);
  inline void set_solution(const char* value);
  inline void set_solution(const char* value, size_t size);
  inline ::std::string* mutable_solution();
  inline ::std::string* release_solution();
  inline void set_allocated_solution(::std::string* solution);

  // optional string nogood = 13;
  inline bool has_nogood() const;
  inline void clear_nogood();
  static const int kNogoodFieldNumber = 13;
  inline const ::std::string& nogood() const;
  inline void set_nogood(const ::std::string& value);
  inline void set_nogood(const char* value);
  inline void set_nogood(const char* value, size_t size);
  inline ::std::string* mutable_nogood();
  inline ::std::string* release_nogood();
  inline void set_allocated_nogood(::std::string* nogood);

  // optional string info = 14;
  inline bool has_info() const;
  inline void clear_info();
  static const int kInfoFieldNumber = 14;
  inline const ::std::string& info() const;
  inline void set_info(const ::std::string& value);
  inline void set_info(const char* value);
  inline void set_info(const char* value, size_t size);
  inline ::std::string* mutable_info();
  inline ::std::string* release_info();
  inline void set_allocated_info(::std::string* info);

  // optional int32 nogood_bld = 15;
  inline bool has_nogood_bld() const;
  inline void clear_nogood_bld();
  static const int kNogoodBldFieldNumber = 15;
  inline ::google::protobuf::int32 nogood_bld() const;
  inline void set_nogood_bld(::google::protobuf::int32 value);

  // optional bool uses_assumptions = 16;
  inline bool has_uses_assumptions() const;
  inline void clear_uses_assumptions();
  static const int kUsesAssumptionsFieldNumber = 16;
  inline bool uses_assumptions() const;
  inline void set_uses_assumptions(bool value);

  // @@protoc_insertion_point(class_scope:message.Node)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_sid();
  inline void clear_has_sid();
  inline void set_has_pid();
  inline void clear_has_pid();
  inline void set_has_alt();
  inline void clear_has_alt();
  inline void set_has_kids();
  inline void clear_has_kids();
  inline void set_has_status();
  inline void clear_has_status();
  inline void set_has_restart_id();
  inline void clear_has_restart_id();
  inline void set_has_time();
  inline void clear_has_time();
  inline void set_has_thread_id();
  inline void clear_has_thread_id();
  inline void set_has_label();
  inline void clear_has_label();
  inline void set_has_domain_size();
  inline void clear_has_domain_size();
  inline void set_has_solution();
  inline void clear_has_solution();
  inline void set_has_nogood();
  inline void clear_has_nogood();
  inline void set_has_info();
  inline void clear_has_info();
  inline void set_has_nogood_bld();
  inline void clear_has_nogood_bld();
  inline void set_has_uses_assumptions();
  inline void clear_has_uses_assumptions();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  int type_;
  ::google::protobuf::int32 sid_;
  ::google::protobuf::int32 pid_;
  ::google::protobuf::int32 alt_;
  ::google::protobuf::int32 kids_;
  int status_;
  ::google::protobuf::uint64 time_;
  ::google::protobuf::int32 restart_id_;
  ::google::protobuf::int32 thread_id_;
  ::std::string* label_;
  ::std::string* solution_;
  ::std::string* nogood_;
  float domain_size_;
  ::google::protobuf::int32 nogood_bld_;
  ::std::string* info_;
  bool uses_assumptions_;
  friend void  protobuf_AddDesc_message_2eproto();
  friend void protobuf_AssignDesc_message_2eproto();
  friend void protobuf_ShutdownFile_message_2eproto();

  void InitAsDefaultInstance();
  static Node* default_instance_;
};
// ===================================================================


// ===================================================================

// Node

// required .message.Node.MsgType type = 1;
inline bool Node::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Node::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Node::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Node::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::message::Node_MsgType Node::type() const {
  // @@protoc_insertion_point(field_get:message.Node.type)
  return static_cast< ::message::Node_MsgType >(type_);
}
inline void Node::set_type(::message::Node_MsgType value) {
  assert(::message::Node_MsgType_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:message.Node.type)
}

// optional int32 sid = 2;
inline bool Node::has_sid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Node::set_has_sid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Node::clear_has_sid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Node::clear_sid() {
  sid_ = 0;
  clear_has_sid();
}
inline ::google::protobuf::int32 Node::sid() const {
  // @@protoc_insertion_point(field_get:message.Node.sid)
  return sid_;
}
inline void Node::set_sid(::google::protobuf::int32 value) {
  set_has_sid();
  sid_ = value;
  // @@protoc_insertion_point(field_set:message.Node.sid)
}

// optional int32 pid = 3;
inline bool Node::has_pid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Node::set_has_pid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Node::clear_has_pid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Node::clear_pid() {
  pid_ = 0;
  clear_has_pid();
}
inline ::google::protobuf::int32 Node::pid() const {
  // @@protoc_insertion_point(field_get:message.Node.pid)
  return pid_;
}
inline void Node::set_pid(::google::protobuf::int32 value) {
  set_has_pid();
  pid_ = value;
  // @@protoc_insertion_point(field_set:message.Node.pid)
}

// optional int32 alt = 4;
inline bool Node::has_alt() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Node::set_has_alt() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Node::clear_has_alt() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Node::clear_alt() {
  alt_ = 0;
  clear_has_alt();
}
inline ::google::protobuf::int32 Node::alt() const {
  // @@protoc_insertion_point(field_get:message.Node.alt)
  return alt_;
}
inline void Node::set_alt(::google::protobuf::int32 value) {
  set_has_alt();
  alt_ = value;
  // @@protoc_insertion_point(field_set:message.Node.alt)
}

// optional int32 kids = 5;
inline bool Node::has_kids() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Node::set_has_kids() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Node::clear_has_kids() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Node::clear_kids() {
  kids_ = 0;
  clear_has_kids();
}
inline ::google::protobuf::int32 Node::kids() const {
  // @@protoc_insertion_point(field_get:message.Node.kids)
  return kids_;
}
inline void Node::set_kids(::google::protobuf::int32 value) {
  set_has_kids();
  kids_ = value;
  // @@protoc_insertion_point(field_set:message.Node.kids)
}

// optional .message.Node.NodeStatus status = 6;
inline bool Node::has_status() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void Node::set_has_status() {
  _has_bits_[0] |= 0x00000020u;
}
inline void Node::clear_has_status() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void Node::clear_status() {
  status_ = 0;
  clear_has_status();
}
inline ::message::Node_NodeStatus Node::status() const {
  // @@protoc_insertion_point(field_get:message.Node.status)
  return static_cast< ::message::Node_NodeStatus >(status_);
}
inline void Node::set_status(::message::Node_NodeStatus value) {
  assert(::message::Node_NodeStatus_IsValid(value));
  set_has_status();
  status_ = value;
  // @@protoc_insertion_point(field_set:message.Node.status)
}

// optional int32 restart_id = 7;
inline bool Node::has_restart_id() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void Node::set_has_restart_id() {
  _has_bits_[0] |= 0x00000040u;
}
inline void Node::clear_has_restart_id() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void Node::clear_restart_id() {
  restart_id_ = 0;
  clear_has_restart_id();
}
inline ::google::protobuf::int32 Node::restart_id() const {
  // @@protoc_insertion_point(field_get:message.Node.restart_id)
  return restart_id_;
}
inline void Node::set_restart_id(::google::protobuf::int32 value) {
  set_has_restart_id();
  restart_id_ = value;
  // @@protoc_insertion_point(field_set:message.Node.restart_id)
}

// optional uint64 time = 8;
inline bool Node::has_time() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void Node::set_has_time() {
  _has_bits_[0] |= 0x00000080u;
}
inline void Node::clear_has_time() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void Node::clear_time() {
  time_ = GOOGLE_ULONGLONG(0);
  clear_has_time();
}
inline ::google::protobuf::uint64 Node::time() const {
  // @@protoc_insertion_point(field_get:message.Node.time)
  return time_;
}
inline void Node::set_time(::google::protobuf::uint64 value) {
  set_has_time();
  time_ = value;
  // @@protoc_insertion_point(field_set:message.Node.time)
}

// optional int32 thread_id = 9;
inline bool Node::has_thread_id() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void Node::set_has_thread_id() {
  _has_bits_[0] |= 0x00000100u;
}
inline void Node::clear_has_thread_id() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void Node::clear_thread_id() {
  thread_id_ = 0;
  clear_has_thread_id();
}
inline ::google::protobuf::int32 Node::thread_id() const {
  // @@protoc_insertion_point(field_get:message.Node.thread_id)
  return thread_id_;
}
inline void Node::set_thread_id(::google::protobuf::int32 value) {
  set_has_thread_id();
  thread_id_ = value;
  // @@protoc_insertion_point(field_set:message.Node.thread_id)
}

// optional string label = 10;
inline bool Node::has_label() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void Node::set_has_label() {
  _has_bits_[0] |= 0x00000200u;
}
inline void Node::clear_has_label() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void Node::clear_label() {
  if (label_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    label_->clear();
  }
  clear_has_label();
}
inline const ::std::string& Node::label() const {
  // @@protoc_insertion_point(field_get:message.Node.label)
  return *label_;
}
inline void Node::set_label(const ::std::string& value) {
  set_has_label();
  if (label_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    label_ = new ::std::string;
  }
  label_->assign(value);
  // @@protoc_insertion_point(field_set:message.Node.label)
}
inline void Node::set_label(const char* value) {
  set_has_label();
  if (label_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    label_ = new ::std::string;
  }
  label_->assign(value);
  // @@protoc_insertion_point(field_set_char:message.Node.label)
}
inline void Node::set_label(const char* value, size_t size) {
  set_has_label();
  if (label_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    label_ = new ::std::string;
  }
  label_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:message.Node.label)
}
inline ::std::string* Node::mutable_label() {
  set_has_label();
  if (label_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    label_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:message.Node.label)
  return label_;
}
inline ::std::string* Node::release_label() {
  clear_has_label();
  if (label_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = label_;
    label_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Node::set_allocated_label(::std::string* label) {
  if (label_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete label_;
  }
  if (label) {
    set_has_label();
    label_ = label;
  } else {
    clear_has_label();
    label_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:message.Node.label)
}

// optional float domain_size = 11;
inline bool Node::has_domain_size() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void Node::set_has_domain_size() {
  _has_bits_[0] |= 0x00000400u;
}
inline void Node::clear_has_domain_size() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void Node::clear_domain_size() {
  domain_size_ = 0;
  clear_has_domain_size();
}
inline float Node::domain_size() const {
  // @@protoc_insertion_point(field_get:message.Node.domain_size)
  return domain_size_;
}
inline void Node::set_domain_size(float value) {
  set_has_domain_size();
  domain_size_ = value;
  // @@protoc_insertion_point(field_set:message.Node.domain_size)
}

// optional string solution = 12;
inline bool Node::has_solution() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void Node::set_has_solution() {
  _has_bits_[0] |= 0x00000800u;
}
inline void Node::clear_has_solution() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void Node::clear_solution() {
  if (solution_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    solution_->clear();
  }
  clear_has_solution();
}
inline const ::std::string& Node::solution() const {
  // @@protoc_insertion_point(field_get:message.Node.solution)
  return *solution_;
}
inline void Node::set_solution(const ::std::string& value) {
  set_has_solution();
  if (solution_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    solution_ = new ::std::string;
  }
  solution_->assign(value);
  // @@protoc_insertion_point(field_set:message.Node.solution)
}
inline void Node::set_solution(const char* value) {
  set_has_solution();
  if (solution_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    solution_ = new ::std::string;
  }
  solution_->assign(value);
  // @@protoc_insertion_point(field_set_char:message.Node.solution)
}
inline void Node::set_solution(const char* value, size_t size) {
  set_has_solution();
  if (solution_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    solution_ = new ::std::string;
  }
  solution_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:message.Node.solution)
}
inline ::std::string* Node::mutable_solution() {
  set_has_solution();
  if (solution_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    solution_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:message.Node.solution)
  return solution_;
}
inline ::std::string* Node::release_solution() {
  clear_has_solution();
  if (solution_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = solution_;
    solution_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Node::set_allocated_solution(::std::string* solution) {
  if (solution_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete solution_;
  }
  if (solution) {
    set_has_solution();
    solution_ = solution;
  } else {
    clear_has_solution();
    solution_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:message.Node.solution)
}

// optional string nogood = 13;
inline bool Node::has_nogood() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void Node::set_has_nogood() {
  _has_bits_[0] |= 0x00001000u;
}
inline void Node::clear_has_nogood() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void Node::clear_nogood() {
  if (nogood_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    nogood_->clear();
  }
  clear_has_nogood();
}
inline const ::std::string& Node::nogood() const {
  // @@protoc_insertion_point(field_get:message.Node.nogood)
  return *nogood_;
}
inline void Node::set_nogood(const ::std::string& value) {
  set_has_nogood();
  if (nogood_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    nogood_ = new ::std::string;
  }
  nogood_->assign(value);
  // @@protoc_insertion_point(field_set:message.Node.nogood)
}
inline void Node::set_nogood(const char* value) {
  set_has_nogood();
  if (nogood_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    nogood_ = new ::std::string;
  }
  nogood_->assign(value);
  // @@protoc_insertion_point(field_set_char:message.Node.nogood)
}
inline void Node::set_nogood(const char* value, size_t size) {
  set_has_nogood();
  if (nogood_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    nogood_ = new ::std::string;
  }
  nogood_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:message.Node.nogood)
}
inline ::std::string* Node::mutable_nogood() {
  set_has_nogood();
  if (nogood_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    nogood_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:message.Node.nogood)
  return nogood_;
}
inline ::std::string* Node::release_nogood() {
  clear_has_nogood();
  if (nogood_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = nogood_;
    nogood_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Node::set_allocated_nogood(::std::string* nogood) {
  if (nogood_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete nogood_;
  }
  if (nogood) {
    set_has_nogood();
    nogood_ = nogood;
  } else {
    clear_has_nogood();
    nogood_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:message.Node.nogood)
}

// optional string info = 14;
inline bool Node::has_info() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void Node::set_has_info() {
  _has_bits_[0] |= 0x00002000u;
}
inline void Node::clear_has_info() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void Node::clear_info() {
  if (info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    info_->clear();
  }
  clear_has_info();
}
inline const ::std::string& Node::info() const {
  // @@protoc_insertion_point(field_get:message.Node.info)
  return *info_;
}
inline void Node::set_info(const ::std::string& value) {
  set_has_info();
  if (info_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    info_ = new ::std::string;
  }
  info_->assign(value);
  // @@protoc_insertion_point(field_set:message.Node.info)
}
inline void Node::set_info(const char* value) {
  set_has_info();
  if (info_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    info_ = new ::std::string;
  }
  info_->assign(value);
  // @@protoc_insertion_point(field_set_char:message.Node.info)
}
inline void Node::set_info(const char* value, size_t size) {
  set_has_info();
  if (info_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    info_ = new ::std::string;
  }
  info_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:message.Node.info)
}
inline ::std::string* Node::mutable_info() {
  set_has_info();
  if (info_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    info_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:message.Node.info)
  return info_;
}
inline ::std::string* Node::release_info() {
  clear_has_info();
  if (info_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = info_;
    info_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Node::set_allocated_info(::std::string* info) {
  if (info_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete info_;
  }
  if (info) {
    set_has_info();
    info_ = info;
  } else {
    clear_has_info();
    info_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:message.Node.info)
}

// optional int32 nogood_bld = 15;
inline bool Node::has_nogood_bld() const {
  return (_has_bits_[0] & 0x00004000u) != 0;
}
inline void Node::set_has_nogood_bld() {
  _has_bits_[0] |= 0x00004000u;
}
inline void Node::clear_has_nogood_bld() {
  _has_bits_[0] &= ~0x00004000u;
}
inline void Node::clear_nogood_bld() {
  nogood_bld_ = 0;
  clear_has_nogood_bld();
}
inline ::google::protobuf::int32 Node::nogood_bld() const {
  // @@protoc_insertion_point(field_get:message.Node.nogood_bld)
  return nogood_bld_;
}
inline void Node::set_nogood_bld(::google::protobuf::int32 value) {
  set_has_nogood_bld();
  nogood_bld_ = value;
  // @@protoc_insertion_point(field_set:message.Node.nogood_bld)
}

// optional bool uses_assumptions = 16;
inline bool Node::has_uses_assumptions() const {
  return (_has_bits_[0] & 0x00008000u) != 0;
}
inline void Node::set_has_uses_assumptions() {
  _has_bits_[0] |= 0x00008000u;
}
inline void Node::clear_has_uses_assumptions() {
  _has_bits_[0] &= ~0x00008000u;
}
inline void Node::clear_uses_assumptions() {
  uses_assumptions_ = false;
  clear_has_uses_assumptions();
}
inline bool Node::uses_assumptions() const {
  // @@protoc_insertion_point(field_get:message.Node.uses_assumptions)
  return uses_assumptions_;
}
inline void Node::set_uses_assumptions(bool value) {
  set_has_uses_assumptions();
  uses_assumptions_ = value;
  // @@protoc_insertion_point(field_set:message.Node.uses_assumptions)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace message

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::message::Node_MsgType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::message::Node_MsgType>() {
  return ::message::Node_MsgType_descriptor();
}
template <> struct is_proto_enum< ::message::Node_NodeStatus> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::message::Node_NodeStatus>() {
  return ::message::Node_NodeStatus_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_message_2eproto__INCLUDED
