package hello.hellospring.service;

import hello.hellospring.domain.Member;
import hello.hellospring.repository.MemberRepository;
import hello.hellospring.repository.MemoryMemberRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

//@Service
public class MemberService {
    // 서비스는 비즈니스에 의존적으로 설계
    // repository는 개발자 원하는데로? 하는듯

    private final MemberRepository memberRepository;

    // 자동 의존관계 : (Controller -> ) Service -> Repository
//    @Autowired
    public MemberService(MemberRepository memberRepository) {
        this.memberRepository = memberRepository;
    }

    /**
     * 슬래시별별하고 커쉬엔
     * 회원가입
     */
    public Long join(Member member) {
        // 중복 회원명 금지 조건
        // 이거 = 오른쪽까지 쓰고 커맨드 옵션 V하면 왼쪽 자동생성
        // 옵셔널을 그냥 반환하는건 좋지 않음.
        // 그래서 다다음처럼 사용함
//        Optional<Member> result = memberRepository.findByName(member.getName());
//        // Optional에 값이 있다면 ...
//        result.ifPresent(m -> {
//            throw new IllegalStateException("이미 존재하는 회원입니다.");
//        });

        // 그런데 이런식으로 T/F같이 값이 나오면 메소드로 뽑는게 좋다
        // 이거는 컨트롤T -> extract method
        validateDuplicateMember(member);

        memberRepository.save(member);
        return member.getId();
    }

    private void validateDuplicateMember(Member member) {
        memberRepository.findByName(member.getName())
                .ifPresent(member1 -> {
                    throw new IllegalStateException("이미 존재하는 회원입니다.");
                });
    }

    /**
     * 전체 회원 조회
     *
     * @return
     */
    public List<Member> findMembers() {
        return memberRepository.findAll();
    }

    /**
     * 아이디로 조회
     * @param memberId
     * @return
     */
    public Optional<Member> findOne(Long memberId) {
        return memberRepository.findById(memberId);
    }

}
